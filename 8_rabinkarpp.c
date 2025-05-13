#include <stdio.h>
#include <string.h>
#include <math.h>

#define BASE 256
#define MOD 101

char text[] = "AABCAADAABAABA";
char pattern[] = "AABA";
int n, m;
int patHash = 0;
int winHash = 0;
int h = 1; // BASE^(m-1) % MOD

int main()
{
    n = strlen(text);    // length of text
    m = strlen(pattern); // length of pattern

    // Compute hash of pattern
    for (int i = 0; i < m; i++)
    {
        patHash = (BASE * patHash + pattern[i]) % MOD;
    }

    // Compute hash for first window of text
    for (int i = 0; i < m; i++)
    {
        winHash = (BASE * winHash + text[i]) % MOD;
    }

    // Calculate BASE^(m-1) for rolling hash calculation
    // Used to remove the leftmost character
    for (int i = 0; i < m - 1; i++)
        h = (BASE * h) % MOD;

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++)
    {
        // Check for match if hashes are identical
        if (patHash == winHash)
        {
            int j = 0; // pointer on pattern
            int k = i; // pointer on text
            int match = 1;

            // Use incrementing variables to check match
            while (j < m)
            {
                if (text[k] != pattern[j])
                {
                    match = 0;
                    break;
                }
                j++;
                k++;
            }

            if (match)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash for next window
        // Remove leftmost character and add next character
        if (i < n - m)
        {
            // Remove the leftmost digit
            winHash = (BASE * (winHash - text[i] * h) + text[i + m]) % MOD;

            if (winHash < 0)
                winHash += MOD;
        }
    }

    return 0;
}
