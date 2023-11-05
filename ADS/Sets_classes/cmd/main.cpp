// Orshak Ivan, 1321, 10.09.2023

#include <iostream>
using namespace std;

//#include "vectors.h"
//#include "lists.h"
//#include "bit_arr.h"
#include "btwd.h"

#define NUM_OF_ITER 100000

int main()
{
	unsigned long time1, time2;

	Set A("A", true), B("B", true), C("C", true), D("D", true), E("E", false);

	cout << "The average cardinality is: " << float(A.GetSize() +
		B.GetSize() + C.GetSize() + D.GetSize()) / 4 << endl;

	time1 = clock();
	for (size_t i = 0; i < NUM_OF_ITER; i++) E = (A & B) | (C & D);
	time2 = clock();

	cout << "Result:\nE: ";
	E.Show();

	cout << endl << "Time spent: " << long double(time2 - time1) / CLOCKS_PER_SEC;

	return 0;
}