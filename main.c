#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>

void searchWithAlgorithm(int (*search)(int elem, int* arr, int n), int* arr, int size);

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int* arr = generateArray(n);

    int ch;
    do {
        printf("Options:\n"
        "1 Sequential search\n"
        "2 Sort a copy\n"
        "3 Binary search\n"
        "4 Merge\n"
        "5 Print contents\n"
        "6 Save/Load to file\n"
        "0 Exit\n\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                searchWithAlgorithm(sequentialSearch, arr, n);
                break;
            case 2:
                int* sortedArr = countingSort(arr, n);
                printContents(sortedArr, n);
                free (sortedArr);
                break;
            case 3:
                searchWithAlgorithm(binarySearch, arr, n);
                break;
            case 4:
                int* mergedArr = merge(arr, n);
                printContents(mergedArr, n * 2);
                free(mergedArr);
                break;
            case 5:
                printContents(arr, n);
                break;
            case 6:
                printf("Options:\n"
                "1 Save to file 'array.txt'\n"
                "2 Load from file 'array.txt'\n"
                "0 Abort"
                "\n\n");
                scanf("%d", &ch);
                switch(ch) {
                    case 1:
                        saveToFile(arr, n);
                        break;
                    case 2:
                        n = loadFromFile(&arr);
                        break;
                    case 0:
                    default:
                        break;
                }
                break;
            case 0:
            default:
                break;
        }
        printf("\n");
    } while (ch != 0);

    free(arr);
    return 0;
}

void searchWithAlgorithm(int (*search)(int elem, int* arr, int n), int* arr, int size) {
    int elem;
    printf("Choose a number: ");
    scanf("%d", &elem);
    int index = search(elem, arr, size);
    if (index == -1) {
        printf("Number %d was not found", elem);
    } else {
        printf("Number %d first found at index %d", elem, index);
    }
}