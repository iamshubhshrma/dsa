#include <stdio.h>
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int size)
{
    // Iterate over each element starting from the second element
    for (int step = 1; step < size; step++)
    {
        int key = array[step]; // The element to be positioned
        int j = step - 1;

        // Compare the key with elements on its left and shift larger elements
        // For descending order, change 'key < array[j]' to 'key > array[j]'
        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j]; // Shift the element one position to the right
            --j;                     // Move one position back
        }
        // Insert the key into its correct position
        array[j + 1] = key;
    }
}

int main()
{
    // Initialize an array with unsorted data
    int data[] = {5, 7, 3, 10, 21};

    // Calculate the number of elements in the array
    int size = sizeof(data) / sizeof(data[0]);
    printf("Unsorted Array\n");
    printArray(data, size);

    // Perform insertion sort on the array
    insertionSort(data, size);

    // Display the sorted array
    printf("Sorted array in Ascending Order:\n");
    printArray(data, size);
    return 0; // Indicate successful program termination
}
