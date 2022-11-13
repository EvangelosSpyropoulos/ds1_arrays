#include "arrays.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int* generateArray(int size) {
    srand(time(NULL));
    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        *(arr+i) = rand() % 21 + 30;
    }

    return arr;
}

int sequentialSearch(int elem, int* arr, int size) {
    int i = 0;
    while (i < size) {
        if (*(arr+i) == elem) {
            return i;
        }
        i++;
    }
    return -1;
}

int* countingSort(int* arr, int size) {
    int* bins = (int*) calloc(21, sizeof(int));
    int* sortedArr = (int*) malloc(size * sizeof(int));

    int shift = 30;
    for (int i = 0; i < size; i++) {
        (*(bins + *(arr+i) - shift))++;
    }  

    int index = 0;
    for (int i = 0; i < 21; i++) {
        int occurrences = *(bins+i);
        for (int j = 0; j < occurrences; j++) {
            *(sortedArr + index) = i + shift;
            index++;
        }
    }
    
    free(bins);
    return sortedArr;
}

int binarySearch(int elem, int*arr, int size) {
    int* sortedArr = countingSort(arr, size);
    int low = 0;
    int mid;
    int high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (elem == *(sortedArr + mid)) {
            free (sortedArr);
            return mid;
        } else if (elem < *(sortedArr + mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    free(sortedArr);
    return -1;
}

int* merge(int* arr, int size) {
    int* sortedArr = countingSort(arr, size);
    int* newArr = generateArray(size);
    int* sortedNewArr = countingSort(newArr, size);
    free(newArr);
    int* mergedArr = (int*) malloc(2 * size * sizeof(int));
    
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size && j < size) {
        if (*(sortedArr+i) < *(sortedNewArr+j)) {
            *(mergedArr+k) = *(sortedArr+i);
            i++;
        } else {
            *(mergedArr+k) = *(sortedNewArr+j);
            j++;
        }
        k++;

        if (i == size) {
            memcpy(mergedArr+k, sortedNewArr+j, (size - j) * sizeof(int));
        } else if (j == size) {
            memcpy(mergedArr+k, sortedArr+i, (size - i) * sizeof(int));
        }
    }

    free(sortedArr);
    free(sortedNewArr);
    return mergedArr;
}

void printContents(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

void saveToFile(int* arr, int size) {
    FILE* file;
    file  = fopen("array.txt", "w");

    if (file != NULL) {
        for (int i = 0; i < size; i++) {
            fprintf(file, "%d ", *(arr+i));
        }
        fclose(file);
    }
}

int loadFromFile(int** arr) {
    int size = 0;
    
    FILE* file;
    file  = fopen("array.txt", "r");

    if (file != NULL) {
        while(!feof(file)) {
            size++;
            *arr = (int*) realloc(*arr, size*sizeof(int));
            fscanf(file, "%d ", (*arr)+size-1);
        }
        fclose(file);
    }
    return size;
}