#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int temp;
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i < j) 
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            // Swaping low and high
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }

    // Swaping pivot and high
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
void quickSort(int arr[], int low, int high)
{
    int partitionIndex; // index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // Sort left Subarray
        quickSort(arr, partitionIndex + 1, high); // Sort right Subarray
    }
}
int main()
{
    int arr[] = {7, 0, 58, 4, 1001, 89, 102, 38, 6, 3};
    int size = sizeof(arr) / sizeof(int);
    printf("Before Sorting : ");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("After Sorting : ");
    printArray(arr, size);
    return 0;
}