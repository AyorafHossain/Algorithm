// C program for implementation of Bubble sort
#include <stdio.h>


void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {


        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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



    bubbleSort(arr, n);


    printf("array after bubble sort:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

