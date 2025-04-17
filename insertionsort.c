#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6}; // Array to sort
    int n = 6;                      // Number of elements
    int i, j, key;

    // Start from the second element (index 1)
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // Store the value to insert
        j = i - 1;    // Start comparing from the previous element

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key; // Insert key at the correct position
    }

    // Print the sorted array
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
