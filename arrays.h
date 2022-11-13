#ifndef ARRAYS_H
#define ARRAYS_H

int* generateArray(int size);

// Returns the index of first occurrence,
// -1 if not found
int sequentialSearch(int elem, int* arr, int size);

int* countingSort(int* arr, int size);

// Returns the index of first occurrence,
// -1 if not found
int binarySearch(int elem, int*arr, int size);

int* merge(int* arr, int size);

void printContents(int* arr, int size);
void saveToFile(int* arr, int size);
int loadFromFile(int** arr);

#endif