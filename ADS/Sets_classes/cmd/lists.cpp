// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

#include "lists.h"

Set::Set()
{
	set_name = "";
	set_card = 0;
	set = new list <unsigned char>;
}

Set::Set(string name, bool flag)
{
	set_name = name;
	set = new list <unsigned char>;

	if (flag)
	{
		vector <char> uni = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

		set_card = (rand() * time(NULL)) % 16;

		for (size_t z = 0; z < set_card; z++) random_shuffle(uni.begin(), uni.end());
		for (char i = 0; i < set_card; i++) set -> push_back(uni[i]);

		if (!set->empty()) { set->sort(); }

		cout << "Set " << name << " has been generated: ";
		this->Show();
		cout << endl;
	}
	else set_card = 0;
}

Set Set::operator& (const Set& B)
{
	Set C;
	list <unsigned char> A, X;

	A.insert(A.begin(), set->begin(), set->end());
	X.insert(X.begin(), B.set->begin(), B.set->end());

	while (A.begin() != A.end() && X.begin() != X.end())
	{
		if (A.front() == X.front())
		{
			C.set->push_back(A.front());
			A.pop_front();
			X.pop_front();

			continue;
		}

		if (A.front() > X.front()) { X.pop_front(); continue; }
		else { A.pop_front(); continue; }
	}

	C.set_card = C.set->size();

	return C;
}

Set Set::operator| (const Set& B)
{
	Set C;
	list <unsigned char> A, X;

	A.insert(A.begin(), set->begin(), set->end());
	X.insert(X.begin(), B.set->begin(), B.set->end());

	while (A.begin() != A.end() && X.begin() != X.end())
	{
		if (A.front() == X.front())
		{
			C.set->push_back(X.front());
			A.pop_front();
			X.pop_front();

			continue;
		}

		if (A.front() > X.front())
		{
			C.set->push_back(X.front());
			X.pop_front();

			continue;
		}
		else {
			C.set->push_back(A.front());
			A.pop_front();

			continue;
		}
	}

	if (!A.empty()) C.set->merge(A);
	if (!X.empty()) C.set->merge(X);

	C.set_card = C.set->size();

	return C;
}

void Set::operator= (const Set& B)
{
	if (this != &B)
	{
		set->clear();
		set_card = B.set_card;
		set->merge(*B.set);
	}
}

void Set::Show()
{
	for (auto item : *set) cout << hex << int(item) << " ";
	cout << endl;
}

char Set::GetSize() { return set_card; }