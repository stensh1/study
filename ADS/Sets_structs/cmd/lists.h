// Orshak Ivan, 1321, 10.09.2023
#pragma once

#include <list>
#include <vector>

using namespace std;

// making a 4 lists from 4 vectors
void lsts_v2l(vector < vector <unsigned char>* > vecs, list <unsigned char>* arr_lst[]);

// intersection of 2 lists
list <unsigned char> lst_intersection(list <unsigned char> A, list <unsigned char> B);

// unification of 2 lists
list <unsigned char> lst_unification(list <unsigned char> A, list <unsigned char> B);

// calculating the answer: E = A&B | B&C
list <unsigned char> lst_calculate_res(list <unsigned char>* arr_lst[]);

// list printing
void lst_print(list <unsigned char> lst);
