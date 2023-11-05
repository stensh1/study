// Orshak Ivan, 1321, 10.09.2023
#pragma once

#include <vector>

using namespace std;

// converting input data from vectors to arrays of bits
void bts_v2b(vector < vector <unsigned char>* > vecs, bool(&bts_sets)[4][16]);

// converting arrays of bits to bit words
void bts_b2btw(bool(&bts_sets)[4][16], unsigned short*
	btw_sets[]);

// intersection of 2 arrays of bits
void bts_intersection(bool(&A)[16], bool(&B)[16]);

// unification of 2 arrays of bits
void bts_unification(bool(&A)[16], bool(&B)[16]);

// calculating the answer: E = A&B | B&C
void bts_calculate_res(bool(&bts_sets)[4][16]);

// arrays of bits printing
void bts_print(bool(&bts_set)[16]);

// intersection of 2 bit words
unsigned short btw_intersection(unsigned short A, unsigned short B);

// unification of 2 bit words
unsigned short btw_unification(unsigned short A, unsigned short B);

// calculating the answer: E = A&B | B&C
unsigned short btw_calculate_res(unsigned short* btw_sets[]);

// the final bit word printing
void btw_print(unsigned short btw);
