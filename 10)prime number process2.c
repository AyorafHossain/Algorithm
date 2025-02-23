#include <stdio.h>

int arr[10000000];

int main()
{
    int i, j, n;
    arr[0] = arr[1] = 1; // 0 and 1 are not prime numbers

    printf("Enter range for prime numbers: ");
    scanf("%d", &n);

    // Sieve of Eratosthenes to mark non-prime numbers
    for (i = 2; i <= n; i++)
    {
        if (arr[i] == 0)   // If `i` is prime
        {
            for (j = i + i; j <= n; j += i)
            {
                arr[j] = 1; // Mark multiples of `i` as non-prime
            }
        }
    }

    // Print all prime numbers up to `n`
    printf("Prime numbers are:\n");
    for (i = 2; i <= n; i++)
    {
        if (arr[i] == 0)   // If `i` is prime
        {
            printf("%d ", i);
        }
    }


    return 0;
}
