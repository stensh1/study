// Orshak Ivan, 1321, 10.09.2023

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#include "vectors.h"

int comp(const void* i, const void* j) {
	return *(unsigned char*)i - *(unsigned char*)j;
}

Set::Set()
{
	set_name = "";
	set_card = 0;
	set = new vector <unsigned char>;
}

Set::Set(string name, bool flag)
{
	set_name = name;
	set = new vector <unsigned char>;

	if (flag)
	{
		vector <char> uni = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
		set_card = (rand() * time(NULL)) % 16;

		for (size_t z = 0; z < set_card; z++) random_shuffle(uni.begin(), uni.end());
		for (char i = 0; i < set_card; i++) set -> push_back(uni[i]);

		if (!set->empty()) { qsort(&(*set)[0], set_card, 1,comp); 
		}
		cout << "Set " << name << " has been generated: ";
		this->Show();
		cout << endl;
	}
	else set_card = 0;
}

Set::~Set()
{
	set->clear();
	delete set;
}

Set Set::operator& (const Set& B)
{
	Set C;
	
	for (size_t i = 0, j = 0; i < this->set_card && j < B.set_card; )
	{
		if (this->set->at(i) == B.set->at(j))
		{
			C.set->push_back(this->set->at(i));
			i++;
			j++;

			continue;
		}

		if (this->set->at(i) > B.set->at(j)) { j++; continue; }
		else { i++; continue; }
	}

	C.set_card = C.set->size();

	return C;
}

void Set::operator= (const Set& B)
{
	if (this != &B)
	{
		set->clear();
		set_card = B.set_card;

		for (char i = 0; i < B.set_card; i++) set -> push_back(B.set->at(i));
	}
}

Set Set::operator| (const Set& B)
{
	Set C;
	size_t i, j;

	for (i = 0, j = 0; i < this->set_card && j < B.set_card; )
	{
		if (this->set->at(i) == B.set->at(j))
		{
			C.set->push_back(B.set->at(j));
			i++;
			j++;

			continue;
		}

		if (this->set->at(i) > B.set->at(j))
		{
			C.set->push_back(B.set->at(j));
			j++;

			continue;
		}
		else
		{
			C.set->push_back(this->set->at(i));
			i++;

			continue;
		}
	}

	if (i != this->set_card)
		for (i; i != this->set_card; i++) C.set->push_back(this->set->at(i));

	if (j != B.set_card)
		for (j; j != B.set_card; j++) C.set->push_back(B.set->at(j));

	C.set_card = C.set->size();

	return C;
}

void Set::Show()
{
	for (auto item : *set) cout << hex << int(item) << " ";
	cout << endl;
}

char Set::GetSize() { return set_card; }