#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int temp;
    int isTrue = 0;             //For checking adaptive or not.
    for (int i = 0; i < n; i++)
    {
        printf("%d pass completed\n", i + 1);
        isTrue = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isTrue = 0;
            }
        }
        if (isTrue)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {89,100,105,485};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}