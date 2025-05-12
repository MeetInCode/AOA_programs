#include <stdio.h>

int main()
{
    int A[3][3], B[3][3], C[3][3];
    int P, Q, R, S, T, U, V;

    // Input matrices
    printf("Enter elements of 2x2 matrix A (row-wise):\n");
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of 2x2 matrix B (row-wise):\n");
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            scanf("%d", &B[i][j]);

    // Strassen's formulas
    P = (A[1][1] + A[2][2]) * (B[1][1] + B[2][2]);
    Q = (A[2][1] + A[2][2]) * B[1][1];
    R = A[1][1] * (B[1][2] - B[2][2]);
    S = A[2][2] * (B[2][1] - B[1][1]);
    T = (A[1][1] + A[1][2]) * B[2][2];
    U = (A[2][1] - A[1][1]) * (B[1][1] + B[1][2]);
    V = (A[1][2] - A[2][2]) * (B[2][1] + B[2][2]);

    // Construct result matrix C using Strassen's combinations
    C[1][1] = P + S - T + V;
    C[1][2] = R + T;
    C[2][1] = Q + S;
    C[2][2] = P + R - Q + U;

    // Output result
    printf("Product matrix C:\n");
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
