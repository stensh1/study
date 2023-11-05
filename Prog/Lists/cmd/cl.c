// Orshak Ivan, group 1321, 10.09.2023

#include <stdio.h>
#include "cl.h"

CL* InitCl(float value)
{
	CL* root;

	root = (CL*)malloc(sizeof(CL));
	root->value = value;
	root->pointer = root;

	return(root);
}

CL* AddCl(CL* root, float number)
{
	CL* tmp1, * tmp2, * buff, * ptr;

	if (root == NULL){return InitCl(number);}

	tmp1 = (CL*)malloc(sizeof(CL));
	tmp1->value = number;
	tmp2 = root;
	buff = root;

	do{tmp2 = tmp2->pointer;} 
	while (tmp2->pointer != root);

	if (number < root->value)
	{
		tmp1->pointer = root;
		tmp2->pointer = tmp1;

		return tmp1;
	}

	ptr = root->pointer;

	do
	{
		if (number < ptr->value)
		{
			buff->pointer = tmp1;
			tmp1->pointer = ptr;
			return root;
		}

		buff = ptr;
		ptr = ptr->pointer;
	} while (ptr != root);

	tmp2->pointer = tmp1;
	tmp1->pointer = root;

	return root;
}

void PrintCl(CL* root, FILE* file)
{
	CL* tmp;
	tmp = root;

	do
	{
		fprintf(file, "%f ", tmp->value);
		tmp = tmp->pointer;
	} while (tmp != root);
}

void DeleteCl(CL* root)
{
	CL* ptr = root->pointer;

	do
	{
		CL* buff = ptr->pointer;
		free(ptr);
		ptr = buff;
	} while (ptr != root);

	free(root);
}