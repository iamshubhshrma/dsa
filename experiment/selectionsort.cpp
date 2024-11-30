#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a; // Temporary variable to hold one value
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    // Outer loop to iterate over the array
    for (int step = 0; step < size - 1; step++)
    {
        // Assume the current index contains the minimum element
        int min_idx = step;

        // Inner loop to find the smallest element in the unsorted part of the array
        for (int i = step + 1; i < size; i++)
        {
            // For descending order, change '<' to '>'
            if (array[i] < array[min_idx])
            {
                min_idx = i; // Update the index of the smallest element
            }
        }
        // Swap the found minimum element with the element at the current step
        swap(&array[min_idx], &array[step]);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {20, 12, 10, 15, 2}; // Initialize an array with unsorted data

    // Calculate the number of elements in the array
    int size = sizeof(data) / sizeof(data[0]);

    // Perform selection sort on the array
    selectionSort(data, size);

    // Display the sorted array
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);

    return 0; // Indicate successful program termination
}
