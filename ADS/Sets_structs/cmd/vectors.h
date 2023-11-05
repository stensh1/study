// Orshak Ivan, 1321, 10.09.2023
#pragma once

#include <vector>

using namespace std;

// intersection of 2 vectors
vector <unsigned char> vec_intersection(vector <unsigned char>* A, vector <unsigned char>* B);

// unification of 2 vectors
vector <unsigned char> vec_unification(vector <unsigned char>* A, vector <unsigned char>* B);

// calculating the answer: E = A&B | B&C
vector <unsigned char> vec_calculate_res(vector < vector <unsigned char>* > vecs);

// vector printing
void vec_print(vector <unsigned char> vec);
