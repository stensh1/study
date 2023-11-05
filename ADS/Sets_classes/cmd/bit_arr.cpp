// Orshak Ivan, 1321, 10.09.2023

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

#include "bit_arr.h"

Set::Set()
{
	set_name = "";
	set_card = 0;
	memset(set, false, 16);
}

Set::Set(string name, bool flag)
{
	set_name = name;
	memset(set, false, 16);

	if (flag)
	{
		vector <char> uni = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

		set_card = (rand() * time(NULL)) % 16;

		for (size_t z = 0; z < set_card; z++) random_shuffle(uni.begin(), uni.end());
		for (char i = 0; i < set_card; i++) set[uni[i]] = true;

		cout << "Set " << name << " has been generated: ";
		this->Show();
		cout << endl;
	}
	else set_card = 0;
}

Set Set::operator& (const Set& B)
{
	Set C;
	char cnt = 0;

	for (char i = 0; i < 16; i++) if (set[i] && B.set[i]) { C.set[i] = true; cnt++; }

	C.set_card = cnt;

	return C;
}

Set Set::operator| (const Set& B)
{
	Set C;
	char cnt = 0;

	for (char i = 0; i < 16; i++) if (set[i] || B.set[i]) { C.set[i] = true; cnt++; }

	C.set_card = cnt;

	return C;
}

void Set::operator= (const Set& B) {
	if (this != &B) for (char i = 0; i < 16; i++) set[i] = B.set[i];
}

void Set::Show()
{
	for (char i = 0; i < 16; i++) if (set[i]) cout << hex << int(i) << " ";
	cout << endl;
}

char Set::GetSize() { return set_card; }