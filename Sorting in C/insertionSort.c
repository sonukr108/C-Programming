#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int key, i, j;

    for (i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {8,9,7,5,4,2,3,5,6};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}