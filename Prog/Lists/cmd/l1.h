// Orshak Ivan, group 1321, 10.09.2023
#pragma once

#ifndef L1_H
#define L1_H

typedef struct L1 {
	float value;
	struct L1* pointer;
}L1;

void AddL(L1* root, float val, int pos, int* counter);

#endif /* L1_H */