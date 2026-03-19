2023KUEC2081
ADITYA LASHKARY
SECTION C 

//1
#include <stdio.h>

// Function to find the minimum element in an array
int findMinimum(int arr[], int size) {
    int min = arr[0]; // Assume the first element as minimum
    
    // Iterate through the array to find the minimum element
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    return min;
}

// Function to find the maximum element in an array
int findMaximum(int arr[], int size) {
    int max = arr[0]; // Assume the first element as maximum
    
    // Iterate through the array to find the maximum element
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

int main() {
    int arr[] = {5, 3, 8, 1, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int min = findMinimum(arr, size);
    int max = findMaximum(arr, size);
    
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    
    return 0;
}

//2

#include <stdio.h>

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSelect
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSelect algorithm to find the Kth smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex - low == k - 1) {
            return arr[partitionIndex];
        } else if (partitionIndex - low > k - 1) {
            return quickSelect(arr, low, partitionIndex - 1, k);
        } else {
            return quickSelect(arr, partitionIndex + 1, high, k - partitionIndex + low - 1);
        }
    }
    return -1; // If invalid value of k is given
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 3rd smallest element

    int kthSmallest = quickSelect(arr, 0, n - 1, k);

    if (kthSmallest != -1) {
        printf("The %dth smallest element is: %d\n", k, kthSmallest);
    } else {
        printf("Invalid value of k\n");
    }

    return 0;
}

//3
#include <stdio.h>

// Function to sort an array of 0s, 1s, and 2s
void sort012(int arr[], int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0: // If the element is 0, swap with the element at low index and move low and mid pointers
                arr[mid] = arr[low];
                arr[low] = 0;
                low++;
                mid++;
                break;
            case 1: // If the element is 1, move mid pointer
                mid++;
                break;
            case 2: // If the element is 2, swap with the element at high index and move high pointer
                arr[mid] = arr[high];
                arr[high] = 2;
                high--;
                break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 2, 1, 0, 2, 1, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    sort012(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

//4

#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse an array of integers
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    // Swap elements from the beginning and end of the array until reaching the middle
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    reverseArray(arr, size);

    printf("Reversed array: ");
    printArray(arr, size);

    return 0;
}

//5

#include <stdio.h>

// Function to perform Bubble sort
void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        // Last i elements are already in place, so we don't need to check them again
        for (j = 0; j < size - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

//6


