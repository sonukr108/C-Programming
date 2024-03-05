#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n)
{
    int i, j;
    // Find maximum value in the given array
    int max = maximum(arr, n);

    // Create an array of max size and intialize all elements with zeroes
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Upadate the value in the index of count as given array elements
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {4, 6, 41, 570, 14, 8, 46, 89, 74};
    int size = sizeof(arr) / sizeof(int);
    printf("Before Sorting : ");
    printArray(arr, size);

    countSort(arr,size);

    printf("After Sorting : ");
    printArray(arr, size);
}