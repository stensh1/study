// Orshak Ivan, group 1321, 10.09.2023

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "l1.h"
#include "cl.h"

void main(void)
{
	FILE* f_in, * f_out;
	float num;
	int counter_l1 = 0;
	CL* lst2 = NULL;
	L1 lst1[100], * ptr;

	ptr = &lst1;

	if (((f_in = fopen("input.txt", "r")) == NULL) ||
		((f_out = fopen("output.txt", "w")) == NULL))
	{
		printf("Opening file error!\n");

		return;
	}

	while ((fscanf(f_in, "%f", &num)) != EOF)
	{
		AddL(&lst1, num, counter_l1, &counter_l1);
	}

	while (1)
	{
		lst2 = AddCl(lst2, ptr->value);
		if (ptr->pointer != NULL)
		{
			ptr = ptr->pointer;
		}
		else
		{
			break;
		}
	}

	PrintCl(lst2, f_out);

	fclose(f_in);
	fclose(f_out);
	DeleteCl(lst2);

	return;
}
