#include <stdio.h>
#include <string.h>

#define BASE 256
#define MOD 101

char text[] = "AABAACAADAABAABA";
char pattern[] = "AABA";
int n, m;

int main()
{
    n = strlen(text);
    m = strlen(pattern);

    // Compute hash of pattern
    int patHash = 0;
    for (int i = 0; i < m; i++)
    {
        patHash = (BASE * patHash + pattern[i]) % MOD;
    }

    // Iterate through text and compute hash for each substring of length m
    for (int i = 0; i <= n - m; i++)
    {
        int winHash = 0;
        for (int j = 0; j < m; j++)
        {
            winHash = (BASE * winHash + text[i + j]) % MOD;
        }

        // Compare hashes and check for a match
        if (winHash == patHash)
        {
            int match = 1;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = 0;
                    break;
                }
            }
            if (match)
                printf("Pattern found at index %d\n", i);
        }
    }

    return 0;
}
