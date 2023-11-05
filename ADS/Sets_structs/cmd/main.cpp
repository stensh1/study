// Orshak Ivan, 1321, 10.09.2023

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <cassert>
#include <string>
#include "vectors.h"
#include "lists.h"
#include "tests.h"
#include "bits.h"
#include "generator.h"

#define AUTOGEN
#define NUM_OF_ITER 100000

using namespace std;

//proto
int comp(const void* i, const void* j);
void fill_sets(vector < vector <unsigned char>* > vecs);
//end proto

int main() {
	// enable tests
	test_vec_func();

	// input data
	vector <unsigned char> vec_A, vec_B, vec_C, vec_D;
	// vector of sets pointers
	vector < vector <unsigned char>* > vec_sets = { &vec_A, &vec_B, &vec_C, &vec_D };
	// end of input data

	// lists of input data
	list <unsigned char> lst_A, lst_B, lst_C, lst_D;
	// array of lists pointers
	list <unsigned char>* lst_sets[] = { &lst_A, &lst_B, &lst_C, &lst_D };

	// array of array input data bits
	bool bts_sets[4][16] = { 0 };

	// bit words of input sets
	unsigned short btw_A = 0, btw_B = 0, btw_C = 0, btw_D = 0;

	// array of bit words pointers
	unsigned short* btw_sets[] = { &btw_A, &btw_B , &btw_C , &btw_D };

	// output data
	vector <unsigned char> vec_E;
	list <unsigned char> lst_E;
	unsigned short btw_E;
	//end if output data, bts_E is calculating in bts_sets[0]....

	// clock
	unsigned long time, times[4];

	// Enabling sets auto-generation
#ifdef AUTOGEN
	generate_sets(vec_sets);
#else
	fill_sets(vec_sets);
#endif

	cout << "The average cardinality is: " << avr_card(vec_sets) << endl;

	// Sorting input sets, if !empty
	if (!vec_A.empty()) {qsort(&vec_A[0], vec_A.size(), 1, comp);}
	if (!vec_B.empty()) {qsort(&vec_B[0], vec_B.size(), 1, comp);}
	if (!vec_C.empty()) {qsort(&vec_C[0], vec_C.size(), 1, comp);}
	if (!vec_D.empty()) {qsort(&vec_D[0], vec_D.size(), 1, comp);}

	lsts_v2l(vec_sets, lst_sets);
	bts_v2b(vec_sets, bts_sets);
	bts_b2btw(bts_sets, btw_sets);

	time = clock();
	for (size_t i = 0; i < NUM_OF_ITER; i++) vec_E = vec_calculate_res(vec_sets);
	times[0] = clock() - time;

	time = clock();
	for (size_t i = 0; i < NUM_OF_ITER; i++) lst_E = lst_calculate_res(lst_sets);
	times[1] = clock() - time;

	time = clock();
	for (size_t i = 0; i < NUM_OF_ITER; i++) btw_E = btw_calculate_res(btw_sets);
	times[2] = clock() - time;

	time = clock();
	for (size_t i = 0; i < NUM_OF_ITER; i++) bts_calculate_res(bts_sets); // bts_E
	times[3] = clock() - time;

	// printing results:
	cout << "1. Result in vectors:\nE: ";
	vec_print(vec_E);
	cout << "Time spent: " << long double(times[0]) / CLOCKS_PER_SEC;
	cout << endl << endl;

	cout << "2. Result in lists:\nE: ";
	lst_print(lst_E);
	cout << "Time spent: " << long double(times[1]) / CLOCKS_PER_SEC;
	cout << endl << endl;

	cout << "3. Result in bit words:\nE: ";
	btw_print(btw_E);
	cout << "Time spent: " << long double(times[2]) / CLOCKS_PER_SEC;
	cout << endl << endl;

	cout << "4. Result in bit array:\nE: ";
	bts_print(bts_sets[0]);
	cout << "Time spent: " << long double(times[3]) / CLOCKS_PER_SEC;
	cout << endl << endl;

	return 0;
}

// compare func for qsort
int comp(const void* i, const void* j)
{
	return *(unsigned char*)i - *(unsigned char*)j;
}

// filling in initial sets
void fill_sets(vector < vector <unsigned char>* > vecs)
{
	for (char i = 0; i < 4; i++)
	{
		string input_str;
		cout << "Fill the set " << char(i + 65) << ": ";
		getline(cin, input_str);

		for (unsigned char ch : input_str)
		{
			if (ch > 47 && ch < 58)
				vecs[i]->push_back(ch - 48);
			else if (ch > 64 && ch < 71)
				vecs[i]->push_back(ch - 55);
		}

		cout << "// Unknown characters have been removed." << endl;
		cout << "Set " << char(i + 65) << ": ";
		vec_print(*vecs[i]);
		cout << endl << endl;
	}

	cout << endl;
}