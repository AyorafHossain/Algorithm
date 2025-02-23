#include<stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{

    // Initialize pivot to be the first element
    int p = arr[low];

    int i = low;
    int j = high;

    while (i < j)
    {

        while (arr[i] <= p && i <= high - 1)
        {
            i++;
        }


        while (arr[j] > p && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and rightsubarray
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{

    int arr[100],i,n;
    printf("Enter the value of array size:");
    scanf("%d",&n);
    printf("Enter array element:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }



    quickSort(arr, 0,n-1);


    printf("array after quick sort:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
