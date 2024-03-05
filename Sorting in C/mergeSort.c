#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = k = low;
    j = mid + 1;

    // Compare and copy element in the array B
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }

    // Copy remaining elements
    while (i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }
    // Copy all elements Array B to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = B[i];
    }
}
void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, mid, low, high);
    }
}

int main()
{
    int arr[] = {7,77,87,454,45,44,1,5,154,88,17};
    int size = sizeof(arr) / sizeof(int);
    printf("Before Sorting : ");
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("After Sorting : ");
    printArray(arr, size);
    return 0;
}