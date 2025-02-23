#include <stdio.h>
#include <math.h>

#define MAX 10000000
int arr[MAX]; // Array to mark non-prime numbers

int main()
{
    int i, j, n;

    printf("Enter range for prime numbers: ");
    scanf("%d", &n);

    // Sieve of Eratosthenes
    arr[0] = arr[1] = 1; // 0 and 1 are not prime numbers
    for (i = 2; i * i <= n; i++)
    {
        if (arr[i] == 0)   // If `i` is prime
        {
            for (j = i * i; j <= n; j += i)   // Start from i^2
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
    printf("\n");

    return 0;
}

