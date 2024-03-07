#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    { // Start from 1 as arr[0] is always sorted
        int currentElement = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > currentElement)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Finally place the Current element at its correct position.
        arr[j + 1] = currentElement;
    }
}
int main()
{
    int arr[] = {9, 6, 7, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

