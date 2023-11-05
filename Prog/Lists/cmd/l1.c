// Orshak Ivan, group 1321, 10.09.2023

#include <stdio.h>
#include "l1.h"

void AddL(L1* root, float val, int pos, int* counter)
{
	int i;
	L1* tmp;
	L1* ptr = root;

	root[*counter].value = val;

	if (*counter == 0)
	{
		ptr->pointer = NULL;
		(*counter)++;

		return;
	}

	if (pos == 0)
	{
		ptr->pointer = root;
		root = ptr;

		return;
	}

	for (i = 0; i < pos && ptr->pointer != NULL; i++)
	{
		ptr = ptr->pointer;
	}

	tmp = ptr->pointer;

	ptr->pointer = &root[*counter];
	root[*counter].pointer = tmp;
	(*counter)++;

	return;
}
