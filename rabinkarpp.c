#include <stdio.h>
#include <string.h>

#define BASE 256
#define MOD 101

int main()
{
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    int n = strlen(text);
    int m = strlen(pattern);

    int i, j;
    int patHash = 0, winHash = 0, h = 1;

    // Calculate h = (BASE^(m-1)) % MOD
    for (i = 0; i < m - 1; i++)
        h = (h * BASE) % MOD;

    // Calculate initial hash values
    for (i = 0; i < m; i++)
    {
        patHash = (BASE * patHash + pattern[i]) % MOD;
        winHash = (BASE * winHash + text[i]) % MOD;
    }

    // Slide window over text
    for (i = 0; i <= n - m; i++)
    {
        if (patHash == winHash)
        {
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;
            if (j == m)
                printf("Pattern found at index %d\n", i);
        }
        // Update hash for next window
        if (i < n - m)
        {
            winHash = (BASE * (winHash - text[i] * h) + text[i + m]) % MOD;
            if (winHash < 0)
                winHash += MOD;
        }
    }
    return 0;
}
