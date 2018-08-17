#pragma once
#include <string>
#include <cstdlib>

using String = std::string;

class Sort {
public:
	Sort(); // constructor
	void quickSort(int[], int);
	void descendingSort(int[], int);

private:
	int partition(int[], int, int);
	int partitionRandom(int[], int, int);
	void quickSortHelper(int[], int , int);
};
