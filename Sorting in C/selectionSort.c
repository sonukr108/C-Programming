#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int minIndex,temp;
    for (int i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {7, 1, 58, 4, 38, 6, 3};
    int size = sizeof(arr) / sizeof(int);
    printf("Before Sorting : ");
    printArray(arr, size);
    selectionSort(arr,size);
    printf("After Sorting : ");
    printArray(arr, size);
    return 0;
}