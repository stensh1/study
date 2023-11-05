// Orshak Ivan, 1321, 10.09.2023

#include <iostream>
#include "vectors.h"

vector <unsigned char> vec_intersection(vector <unsigned char>* A, vector <unsigned char>* B)
{
	vector <unsigned char> vec_result = {};

	for (size_t ptrA = 0, ptrB = 0; ptrA < A->size() && ptrB < B -> size(); )
	{
		if (A->at(ptrA) == B->at(ptrB))
		{
			vec_result.push_back(A->at(ptrA));
			ptrA++;
			ptrB++;

			continue;
		}

		if (A->at(ptrA) > B->at(ptrB))
		{
			ptrB++;

			continue;
		}
		else {
			ptrA++;

			continue;
		}
	}

	return vec_result;
}

vector <unsigned char> vec_unification(vector <unsigned char>* A, vector <unsigned char>* B)
{
	vector <unsigned char> vec_result;
	size_t ptrA, ptrB;

	for (ptrA = 0, ptrB = 0; ptrA < A->size() && ptrB < B -> size(); )
	{
		if (A->at(ptrA) == B->at(ptrB))
		{
			vec_result.push_back(B->at(ptrB));
			ptrA++;
			ptrB++;

			continue;
		}

		if (A->at(ptrA) > B->at(ptrB))
		{
			vec_result.push_back(B->at(ptrB));
			ptrB++;

			continue;
		}
		else {
			vec_result.push_back(A->at(ptrA));
			ptrA++;

			continue;
		}
	}

	if (ptrA != A->size()) for (ptrA; ptrA != A->size(); ptrA++) vec_result.push_back(A->at(ptrA));
	if (ptrB != B->size()) for (ptrB; ptrB != B->size(); ptrB++) vec_result.push_back(B->at(ptrB));

	return vec_result;
}

vector <unsigned char> vec_calculate_res(vector < vector <unsigned char>* > vecs)
{
	vector <unsigned char> tmp1, tmp2;

	tmp1 = vec_intersection(vecs[0], vecs[1]);
	tmp2 = vec_intersection(vecs[2], vecs[3]);

	return vec_unification(&tmp1, &tmp2);
}

void vec_print(vector <unsigned char> vec)
{
	for (auto item : vec) cout << hex << int(item) << " ";

	cout << endl;
}