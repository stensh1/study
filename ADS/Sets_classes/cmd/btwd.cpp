// Orshak Ivan, 1321, 10.09.2023
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stdlib.h>

using namespace std;

#include "btwd.h"

Set::Set()
{
	set_name = "";
	set_card = 0;
	set = 0;
}

Set::Set(string name, bool flag)
{
	set_name = name;
	set = 0;

	if (flag)
	{
		vector <char> uni = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

		set_card = (rand() * time(NULL)) % 16;

		for (size_t z = 0; z < set_card; z++) random_shuffle(uni.begin(), uni.end());
		for (size_t i = 0; i < set_card; i++)
		{
			unsigned short tmp = 1;
			tmp <<= 15 - uni[i];
			set |= tmp;
		}

		cout << "Set " << name << " has been generated: ";
		this->Show();
		cout << endl;
	}
	else set_card = 0;
}

Set Set::operator& (const Set& B)
{
	Set C;
	unsigned int cnt = 0;

	C.set = set & B.set;

	for (unsigned short tmp = C.set; tmp != 0; tmp >>= 1) cnt += tmp & 1;

	C.set_card = cnt;

	return C;
}

Set Set::operator| (const Set& B)
{
	Set C;
	unsigned int cnt = 0;

	C.set = set | B.set;

	for (unsigned short tmp = C.set; tmp != 0; tmp >>= 1) cnt += tmp & 1;

	C.set_card = cnt;

	return C;
}

void Set::operator= (const Set& B) {
	if (this != &B) set = B.set;
}

void Set::Show()
{
	list <char> result = {};
	unsigned short tmp = set;

	for (char i = 15; i >= 0; i--)
	{
		if (tmp & 1) result.push_back(i);
		tmp >>= 1;
	}

	while (!result.empty())
	{
		cout << hex << int(result.back()) << " ";
		result.pop_back();
	}

	cout << endl;
}

char Set::GetSize() { return set_card; }
