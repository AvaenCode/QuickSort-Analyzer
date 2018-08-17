#include "Sort.h"

Sort::Sort() { }

int Sort::partition(int arr[], int low, int high)
{
	// Sets the pivot.
	int pivot = arr[high]; 

	// Index of the smaller element.
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than or equal to pivot. Increment and swap.
		if (arr[j] <= pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int Sort::partitionRandom(int arr[], int low, int high)
{
	// Randomly generates a number within our bounds
	int random = low + rand() % (high - low);

	// Swap arr[random] with arr[high]
	std::swap(arr[random], arr[high]);
	return partition(arr, low, high);
}

void Sort::quickSortHelper(int arr[], int low, int high) 
{
	if (low < high) {

		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partitionRandom(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortHelper(arr, low, pi - 1);
		quickSortHelper(arr, pi + 1, high);
	}
}

void Sort::quickSort(int arr[], int length)
{
	quickSortHelper(arr, 0, length - 1);
}

void Sort::descendingSort(int arr[], int length)
{
	// CEIndex - Current Element Index, NEIndex - Next Element Index.
	int CEIndex, NEIndex, key;

	for (CEIndex = 1; CEIndex < length; CEIndex++) {
		NEIndex = CEIndex;

		// While the next element index is greater than zero and the current element is greater than the next element...
		while (NEIndex > 0 && arr[NEIndex - 1] < arr[NEIndex]) {
			key = arr[NEIndex];
			arr[NEIndex] = arr[NEIndex - 1];
			arr[NEIndex - 1] = key;
			NEIndex--;
		}
	}
}
