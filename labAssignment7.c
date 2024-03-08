#include <stdio.h>

#define ARRAY_SIZE 9

//ex
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//swapping
void bubbleSort(int arr[], int n) {
    int i, j, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // If we haven't made any swaps in this inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void countSwaps(int arr[], int n, char *sortType) {
    int swapCount = 0;
    int valueCounts[ARRAY_SIZE] = {0}; // Initialize with zeros

    if (sortType == "Bubble") {
        bubbleSort(arr, n);
    } else if (sortType == "Selection") {
        selectionSort(arr, n);
    } else {
        printf("Invalid sort type\n");
        return;
    }

    // Count swaps for each value
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((sortType == "Bubble" && arr[j] > arr[j + 1]) ||
                (sortType == "Selection" && arr[j] > arr[i])) {
                swapCount++;
                valueCounts[arr[j]]++;
            }
        }
    }

    printf("%s Sort:\n", sortType);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (valueCounts[i] > 0) {
            printf("%d: %d times swapped\n", i, valueCounts[i]);
        }
    }
    printf("Total number of swaps: %d\n", swapCount);
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    countSwaps(arr1, ARRAY_SIZE, "Bubble");
    printf("\n");
    countSwaps(arr2, ARRAY_SIZE, "Selection");

    return 0;
}