#include <stdio.h>

#define MAX 100

int temp[MAX]; // Temporary array used for merging

// Merge two sorted parts of the array
void merge(int array[], int left, int mid, int right)
{
    int i = left;    // Start of left part
    int j = mid + 1; // Start of right part
    int k = 0;       // Index for temp[]

    // Compare and copy smaller elements
    while (i <= mid && j <= right)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    // Copy remaining elements from left part
    while (i <= mid)
        temp[k++] = array[i++];

    // Copy remaining elements from right part
    while (j <= right)
        temp[k++] = array[j++];

    // Copy merged elements back to array[]
    for (i = 0; i < k; i++)
        array[left + i] = temp[i];
}

// Recursively divide and sort the array
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(array, left, mid);      // Sort left part
        mergeSort(array, mid + 1, right); // Sort right part
        merge(array, left, mid, right);   // Merge both parts
    }
}

// Print elements of the array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[] = {5, 2, 8, 4, 1}; // Sample input
    int size = 5;

    printf("Before sorting:\n");
    printArray(array, size);

    mergeSort(array, 0, size - 1); // Sort the array

    printf("After sorting:\n");
    printArray(array, size);

    return 0;
}
