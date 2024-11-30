// Quick sort implementation
#include <stdio.h>
// Function to swap two elements in an array
void swap(int *a, int *b)
{
    int t = *a; // Store the value of the first element in a temporary variable
    *a = *b;    // Assign the value of the second element to the first
    *b = t;     // Assign the value of the temporary variable to the second element
}

// Function to partition the array based on a pivot element
int partition(int array[], int low, int high)
{
    int pivot = array[high]; // Select the rightmost element as the pivot
    int i = (low - 1);       // Pointer for the smaller element

    // Iterate through the array, comparing elements with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot) // If the current element is smaller than or equal to the pivot
        {
            i++;                        // Increment the smaller element pointer
            swap(&array[i], &array[j]); // Swap the elements
        }
    }

    // Place the pivot element at the correct position
    swap(&array[i + 1], &array[high]);
    return (i + 1); // Return the partition index
}

// Recursive function to perform Quick Sort
void quickSort(int array[], int low, int high)
{
    if (low < high) // Base case: Stop when the array has one or zero elements
    {
        int pi = partition(array, low, high); // Partition the array and get the pivot index

        quickSort(array, low, pi - 1);  // Recursively sort the left subarray
        quickSort(array, pi + 1, high); // Recursively sort the right subarray
    }
}

// Function to print elements of an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]); // Print each element followed by a space
    }
    printf("\n"); // Add a newline at the end
}

// Driver function to test the Quick Sort algorithm
int main()
{
    int data[] = {8, 7, 2, 1, 0, 9, 6};     // Define an unsorted array
    int n = sizeof(data) / sizeof(data[0]); // Calculate the size of the array

    printf("Unsorted Array\n");
    printArray(data, n); // Display the unsorted array

    quickSort(data, 0, n - 1); // Perform Quick Sort

    printf("Sorted array in ascending order: \n");
    printArray(data, n); // Display the sorted array
}
