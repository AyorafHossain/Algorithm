#include<stdio.h>
int main()
{
    int i, j, n, a[100], min, temp;
    printf("Enter array size n: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++)
    {
        min = i;  // Assume i is the minimum index

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])  // Compare with min, not a[i]
            {
                min = j;  // Update minimum index
            }
        }

        if(min != i) // Swap only if needed
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
