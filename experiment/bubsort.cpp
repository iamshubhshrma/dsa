#include <stdio.h>
void bubbleSort(int array[], int size)
{
    // Outer loop to control the number of passes
    for (int step = 0; step < size - 1; ++step)
    {
        // Inner loop to compare and swap adjacent elements
        for (int i = 0; i < size - step - 1; ++i)
        {
            // Compare two adjacent elements
            // Swap if the current element is greater than the next (for ascending order)
            if (array[i] > array[i + 1])
            {
                // Temporary variable for swapping
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
// Function to print the elements of an array
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
    // Initialize an array with unsorted data
    int data[] = {-2, 45, 0, 11, -9};

    // Calculate the number of elements in the array
    int size = sizeof(data) / sizeof(data[0]);
    printf("Unsorted Array\n");
    printArray(data, size);
    bubbleSort(data, size); // Perform bubble sort on the array

    // Display the sorted array
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);
    return 0; // Indicate successful program termination
}
