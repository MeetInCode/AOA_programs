#include <stdio.h>

// Global variables
int profit[100];
int weight[100];
int capacity;

// Function to find maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Recursive function to solve 0/1 Knapsack
int knapsack(int curr_weight, int n)
{
    // Base case: no items left or weight is 0
    if (n == 0 || curr_weight == 0)
        return 0;

    // If weight of current item is more than capacity, skip itt
    if (weight[n - 1] > curr_weight)
        return knapsack(curr_weight, n - 1);
    else
    {
        // Option 1: include the item
        int include = profit[n - 1] + knapsack(curr_weight - weight[n - 1], n - 1);

        // Option 2: exclude the item
        int exclude = knapsack(curr_weight, n - 1);

        // Return the better of the two choices
        return max(include, exclude);
    }
}

int main()
{
    // Profit and weight of each item - set values directly to global arrays
    profit[0] = 60;
    profit[1] = 100;
    profit[2] = 120;

    weight[0] = 10;
    weight[1] = 20;
    weight[2] = 30;

    // Set capacity
    capacity = 50;

    // Number of items
    int n = 3;

    // Call the knapsack function
    int max_profit = knapsack(capacity, n);

    // Print the result
    printf("Maximum profit in knapsack = %d\n", max_profit);

    return 0;
}
