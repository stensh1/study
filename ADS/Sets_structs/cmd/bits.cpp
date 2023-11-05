// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include <list>
#include "vectors.h"

using namespace std;

void bts_v2b(vector < vector <unsigned char>* > vecs, bool(&bts_sets)[4][16])
{
	for (char i = 0; i < 4; i++)
		for (unsigned char item : *vecs[i])
			bts_sets[i][item] = true;
}

void bts_b2btw(bool(&bts_sets)[4][16], unsigned short* btw_sets[])
{
	for (char j = 0; j < 4; j++)
	{
		unsigned short bts_word = 0;

		for (size_t i = 0; i < sizeof(bts_sets[j]); i++)
			if (bts_sets[j][i])
			{
				unsigned short tmp = 1;
				tmp = tmp << 15 - i;
				bts_word = bts_word | tmp;
			}

		*btw_sets[j] = bts_word;
	}
}

void bts_intersection(bool(&A)[16], bool(&B)[16])
{
	for (char i = 0; i < 16; i++)
		if (!(A[i] && B[i]))
			A[i] = false;
}

void bts_unification(bool(&A)[16], bool(&B)[16])
{
	for (char i = 0; i < 16; i++)
		if (A[i] || B[i])
			A[i] = true;
}

void bts_calculate_res(bool(&bts_sets)[4][16])
{
	bts_intersection(bts_sets[0], bts_sets[1]);
	bts_intersection(bts_sets[2], bts_sets[3]);
	bts_unification(bts_sets[0], bts_sets[2]);
}

void bts_print(bool(&bts_set)[16])
{
	for (char i = 0; i < 16; i++)
		if (bts_set[i])
			cout << hex << int(i) << " ";

	cout << endl;
}
unsigned short btw_intersection(unsigned short A, unsigned short B) 
{
	return A & B;
}

unsigned short btw_unification(unsigned short A, unsigned short B)
{
	return A | B;
}

unsigned short btw_calculate_res(unsigned short* btw_sets[])
{
	unsigned short tmp1, tmp2;
	tmp1 = btw_intersection(*btw_sets[0], *btw_sets[1]);
	tmp2 = btw_intersection(*btw_sets[2], *btw_sets[3]);

	return btw_unification(tmp1, tmp2);
}

void btw_print(unsigned short btw)
{
	list <char> result = {};

	for (char i = 15; i >= 0; i--)
	{
		if (btw & 1)
			result.push_back(i);

		btw = btw >> 1;
	}

	while (!result.empty())
	{
		cout << hex << int(result.back()) << " ";
		result.pop_back();
	}

	cout << endl;
}