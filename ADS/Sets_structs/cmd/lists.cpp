// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include "lists.h"

using namespace std;

void lsts_v2l(vector < vector <unsigned char>* > vecs, list <unsigned char>* arr_lst[])
{
	for (char i = 0; i < 4; i++)
		for (unsigned char item : *vecs[i])
			arr_lst[i]->push_back(item);
}

list <unsigned char> lst_intersection(list <unsigned char> A, list <unsigned char> B)
{
	list <unsigned char> lst_result;

	while (A.begin() != A.end() && B.begin() != B.end())
	{
		if (A.front() == B.front())
		{
			lst_result.push_back(A.front());
			A.pop_front();
			B.pop_front();

			continue;
		}

		if (A.front() > B.front())
		{
			B.pop_front();

			continue;
		}
		else {
			A.pop_front();

			continue;
		}
	}

	return lst_result;
}

list <unsigned char> lst_unification(list <unsigned char> A, list <unsigned char> B)
{
	list <unsigned char> lst_result;

	lst_result.clear();

	while (A.begin() != A.end() && B.begin() != B.end())
	{
		if (A.front() == B.front())
		{
			lst_result.push_back(B.front());
			B.pop_front();
			A.pop_front();

			continue;
		}

		if (A.front() > B.front())
		{
			lst_result.push_back(B.front());
			B.pop_front();

			continue;
		}
		else {
			lst_result.push_back(A.front());
			A.pop_front();

			continue;
		}
	}

	if (!A.empty()) lst_result.merge(A);

	if (!B.empty()) lst_result.merge(B);

	return lst_result;
}
list <unsigned char> lst_calculate_res(list <unsigned char>* arr_lst[])
{
	list <unsigned char> tmp1, tmp2;
	tmp1 = lst_intersection(*arr_lst[0], *arr_lst[1]);
	tmp2 = lst_intersection(*arr_lst[2], *arr_lst[3]);

	return lst_unification(tmp1, tmp2);
}

void lst_print(list <unsigned char> lst)
{
	for (auto item : lst) cout << hex << int(item) << " ";

	cout << endl;
}