// Orshak Ivan, 1321, 10.09.2023
#pragma once

#include <string>

using namespace std;

class Set
{
private:
	const char card_uni = 16;
	string set_name;
	char set_card;
	unsigned short set;
public:
	Set();
	Set(string, bool);
	Set operator& (const Set&);
	Set operator| (const Set&);
	void operator = (const Set&);
	void Show();
	char GetSize();
};