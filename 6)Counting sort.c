#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n)
{
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);

    // Create the count array
    int count[max+1];

    // Initialize the count array elements to 0
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    // Rewrite the original array using the count array
    i = 0; // counter for count array
    j = 0; // counter for given array A

    while (i <= max)
    {
        while (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        i++;
    }


}

int main()
{
    int A[1000],n,i;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array element:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}
