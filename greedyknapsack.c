#include <stdio.h>

// Maximum number of items
#define MAX 100

// Arrays to store item properties
int id[MAX];
float profit[MAX], weight[MAX], ratio[MAX];

// Find item with highest profit/weight ratio
int findMaxRatioIndex(int n)
{
    int index = -1;
    float maxRatio = -1;
    for (int i = 0; i < n; i++)
    {
        if (ratio[i] > maxRatio)
        {
            maxRatio = ratio[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int n;
    float cap, total = 0, currWeight = 0;

    // Get number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Knapsack problems using Greedy Algorithm:\n");

    // Input items data and calculate profit/weight ratio
    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;
        printf("Enter Weight and Profit for item[%d]: \n", i);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    // Get knapsack capacity
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &cap);

    printf("\nItem\tProfit\tWeight\tRatio\tTaken\n");

    // Process items until knapsack is full
    while (currWeight < cap)
    {
        // Get next best item by ratio
        int idx = findMaxRatioIndex(n);
        if (idx == -1)
            break;

        // If item fits completely
        if (currWeight + weight[idx] <= cap)
        {
            currWeight += weight[idx];
            total += profit[idx];
            printf("%d\t%.2f\t%.2f\t%.2f\t1.00\n", id[idx], profit[idx], weight[idx], ratio[idx]);
            ratio[idx] = -1; // Mark item as used
        }
        // If only fraction of item fits
        else
        {
            float remain = cap - currWeight;
            float frac = remain / weight[idx];
            total += profit[idx] * frac;
            currWeight += remain;
            printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n", id[idx], profit[idx], weight[idx], ratio[idx], frac);
            break;
        }
    }

    // Display final profit
    printf("\nTotal Profit: %.2f\n", total);
    return 0;
}
