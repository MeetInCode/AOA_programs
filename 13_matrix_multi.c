#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, k, len, cost;
    int d[100];      // Dimensions array
    int C[100][100]; // DP table

    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions (n+1 numbers): ");
    for (i = 0; i <= n; i++)
        scanf("%d", &d[i]);

    // Initialize diagonal to 0 (cost for single matrix)
    for (i = 1; i <= n; i++)
        C[i][i] = 0;

    // len = chain length
    for (len = 2; len <= n; len++)
    {
        for (i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            C[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                cost = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (cost < C[i][j])
                    C[i][j] = cost;
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", C[1][n]);
    return 0;
}
