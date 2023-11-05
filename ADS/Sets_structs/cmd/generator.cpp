// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include <algorithm>
#include "generator.h"
#include "vectors.h"

using namespace std;

void generate_sets(vector < vector <unsigned char>* > vecs)
{
	vector <char> uni = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	char N;

	for (char j = 0; j < 4; j++)
	{
		N = (rand() * time(NULL)) % 16;

		for (size_t z = 0; z < N; z++)
			random_shuffle(uni.begin(), uni.end());

		for (char i = 0; i < N; i++)
			vecs[j]->push_back(uni[i]);

		cout << "Set " << char(j + 65) << " has been generated:";
		vec_print(*vecs[j]);
		cout << endl;
	}
}

float avr_card(vector < vector <unsigned char>* > vecs) {
	return float(vecs[0]->size() + vecs[1]->size() + vecs[2] -> size() + vecs[3]->size()) / 4;}