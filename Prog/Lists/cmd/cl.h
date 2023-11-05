// Orshak Ivan, group 1335, 12.01.2023
#pragma once

#include <stdlib.h>
#ifndef CL_H
#define CL_H

typedef struct CL {
	float value;
	struct CL* pointer;
}CL;

CL* InitCl(float value);
CL* AddCl(CL* root, float number);
void PrintCl(CL* root, FILE* file);
void DeleteCl(CL* root);

#endif /* CL_H */
