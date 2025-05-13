#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void temp() {
    int arr[5];
    int i, n;

    clrscr();  // Clear the screen

    n = 5;
    printf("Enter 5 integers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nHello World");

    getch();  // Wait for key press
}

#include <stdio.h>

int globalMin, globalMax;

// Recursively finds the minimum and maximum values in the array between indices 'low' and 'high'
void findMinMax(int arr[], int low, int high)
{
    int mid;

    //? Base Case 1: If there's only one element (low == high)
    if (low == high)
    {
        // Update global min and max if necessary
        if (arr[low] < globalMin)
            globalMin = arr[low];
        if (arr[low] > globalMax)
            globalMax = arr[low];
        return; // No further division needed for a single element
    }

    //? Base Case 2: If there are exactly two elements (high == low + 1)
    if (high == low + 1)
    {
        // Compare the two elements and update global min/max
        if (arr[low] < arr[high])
        {
            if (arr[low] < globalMin)
                globalMin = arr[low];
            if (arr[high] > globalMax)
                globalMax = arr[high];
        }
        else
        {
            if (arr[high] < globalMin)
                globalMin = arr[high];
            if (arr[low] > globalMax)
                globalMax = arr[low];
        }
        return; // No need to further divide when there are only two elements
    }

    //? Recursive Case: If there are more than two elements
    mid = low + (high - low) / 2; // Find the midpoint of the current range
    // Recursively find min and max in the left half of the array
    findMinMax(arr, low, mid);
    // Recursively find min and max in the right half of the array
    findMinMax(arr, mid + 1, high);
}

int main()
{
    temp();
    int arr[] = {20, 20, 60, 10, 80, 50, 40, 70, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);            // Calculate the number of elements in the array

    // Initialize global min and max with the first element of the array
    globalMin = globalMax = arr[0];

    // Call the function to find the min and max in the array
    findMinMax(arr, 0, n - 1);

    // Print the final minimum and maximum values found
    // printf("Min: %d, Max: %d\n", globalMin, globalMax);
    return 0; // Exit program successfully
}
