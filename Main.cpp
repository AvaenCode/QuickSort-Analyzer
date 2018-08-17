#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <chrono>
#include "Sort.h"

using String = std::string;
using namespace std::chrono;

// Declare prototype functions here.
void printIntroduction();
void printArray(int[], int);
void generateRandomArray(int[], int);
void quickSortOfSize100();
void quickSortOfSize1000();
void quickSortOfSize10000();
void quickSortCaseB();

// Declare our sort instance
Sort SortingMethod;

int main() 
{
	printIntroduction();
	quickSortOfSize100();
	quickSortOfSize1000();
	quickSortOfSize10000();
	quickSortCaseB();
	quickSortOfSize100();

	return 0;
}


void printIntroduction()
{
	std::cout << " ___________________________________________________________________________________________" << std::endl;
	std::cout << "|                  ### Welcome to the quick sort runtime analyzer! ###                      |" << std::endl;
	std::cout << "|                                                                                           |" << std::endl;
	std::cout << "| The following program will run a quick sort on three different cases!                     |" << std::endl;
	std::cout << "| The program can be configured by adjusting the global length variable in the Main.cpp.    |" << std::endl;
	std::cout << "|                                                                                           |" << std::endl;
	std::cout << "| The three cases that will be looked into are:                                             |" << std::endl;
	std::cout << "|    - Case 1: Quick sort on an array of size n = 100.                                      |" << std::endl;
	std::cout << "|    - Case 2: Quick sort on an array of size n = 1000.                                     |" << std::endl;
	std::cout << "|    - Case 3: Quick sort on an array of size n = 10000.                                    |" << std::endl;
	std::cout << "|    - Case B: Quick sort on an array that is already sorted (worst case).                  |" << std::endl;
	std::cout << "|    - Case C: Quick sort on an array that is not already sorted (best case).               |" << std::endl;
	std::cout << "|                                                                                           |" << std::endl;
	std::cout << "| Note: The array elements will be randomly generated integers from 0 - 99.                 |" << std::endl;
	std::cout << "|___________________________________________________________________________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void printArray(int arr[], int n)
{
	std::cout << "[ ";
	for (int i = 0; i<n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "... ]";
	std::cout << "\n\n";
}

void generateRandomArray(int arr[], int n)
{
	for (int i = 0; i<n; i++) {
		arr[i] = rand() % 99; // generate a random integer from 0 - 99.
	}
}

void quickSortOfSize100() {
	int arr[100];

	// Generate an array of random integers, print it, sort it and print sorted.
	generateRandomArray(arr, 100);

	std::cout << "Generated array printing the first few values (n = 100): " << std::endl;
	printArray(arr, 100);

	// Start measure time here.
	auto start = high_resolution_clock::now();

	SortingMethod.quickSort(arr, 100);

	// End measure time here.
	auto end = high_resolution_clock::now();

	std::cout << "Performing quick sort and printing the first few sorted values: " << std::endl;
	printArray(arr, 100);

	// Print out runtime in microseconds.
	auto duration = duration_cast<microseconds>(end - start);
	std::cout << "  --> The following runtime of the quick sort algorithm in this case is " << duration.count() << " microseconds. \n" << std::endl;

	std::cout << "                  ________________________________________________________________________________\n" << std::endl;
}

void quickSortOfSize1000() {
	int arr[1000];

	// Generate an array of random integers, print it, sort it and print sorted.
	generateRandomArray(arr, 1000);

	std::cout << "Generated array, printing the first few values (n = 1000): " << std::endl;
	printArray(arr, 110);

	// Start measure time here.
	auto start = high_resolution_clock::now();

	SortingMethod.quickSort(arr, 1000);

	// End measure time here.
	auto end = high_resolution_clock::now();

	std::cout << "Performing quick sort and printing the first few sorted values: " << std::endl;
	printArray(arr, 110);

	// Print out runtime in microseconds.
	auto duration = duration_cast<microseconds>(end - start);
	std::cout << "  --> The following runtime of the quick sort algorithm in this case is " << duration.count() << " microseconds. \n" << std::endl;

	std::cout << "                  ________________________________________________________________________________\n" << std::endl;
}

void quickSortOfSize10000() {
	int arr[10000];

	// Generate an array of random integers, print it, sort it and print sorted.
	generateRandomArray(arr, 10000);

	std::cout << "Generated array printing the first few values (n = 10000): " << std::endl;
	printArray(arr, 120);

	// Start measure time here.
	auto start = high_resolution_clock::now();

	SortingMethod.quickSort(arr, 10000);

	// End measure time here.
	auto end = high_resolution_clock::now();

	std::cout << "Performing quick sort and printing the first few sorted values: " << std::endl;
	printArray(arr, 120);

	// Print out runtime in microseconds.
	auto duration = duration_cast<microseconds>(end - start);
	std::cout << "  --> The following runtime of the quick sort algorithm in this case is " << duration.count() << " microseconds. \n" << std::endl;

	std::cout << "                  ________________________________________________________________________________\n" << std::endl;
}

void quickSortCaseB() 
{

	int arr[100];

	// Generate an array of random integers, print it, sort it and print sorted.
	generateRandomArray(arr, 100);

	// Sort it ascendingly.
	SortingMethod.descendingSort(arr, 100);

	std::cout << "Generated array printing the first few values (n = 100): " << std::endl;
	printArray(arr, 100);

	// Start measure time here.
	auto start = high_resolution_clock::now();

	SortingMethod.quickSort(arr, 100);

	// End measure time here.
	auto end = high_resolution_clock::now();

	std::cout << "Performing quick sort and printing the first few sorted values: " << std::endl;
	printArray(arr, 100);

	// Print out runtime in microseconds.
	auto duration = duration_cast<microseconds>(end - start);
	std::cout << "  --> The following runtime of the quick sort algorithm in this case is " << duration.count() << " microseconds. \n" << std::endl;
	std::cout << "                  ________________________________________________________________________________\n" << std::endl;
}
