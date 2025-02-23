#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n)
{
    // Create a boolean array to track if numbers are prime
    bool isPrime[n + 1];

    // Initialize all entries as true
    for (int i = 0; i <= n; i++)
    {
        isPrime[i] = true;
    }

    // 0 and 1 are not prime numbers
    isPrime[0] = false;
    isPrime[1] = false;

    // Perform the sieve algorithm
    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int multiple = p * p; multiple <= n; multiple += p)
            {
                isPrime[multiple] = false;
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d are:\n", n);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the upper limit: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}
