#include <stdio.h>

// Function to swap two elements (no pointers)
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function as per your logic
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low + 1;
    int j = high;

    while (1) {
        // Move i to the right as long as arr[i] <= pivot
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // Move j to the left as long as arr[j] > pivot
        while (arr[j] > pivot) {
            j--;
        }

        // If i crosses j, break the loop
        if (i > j) {
            break;
        }

        // Swap arr[i] and arr[j]
        swap(arr, i, j);
    }

    // Place the pivot in its correct position
    swap(arr, low, j);

    // Return the index of pivot
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int p = partition(arr, low, high);

        // Sort the left part
        quickSort(arr, low, p - 1);

        // Sort the right part
        quickSort(arr, p + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 3, 7, 6, 2, 5, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
