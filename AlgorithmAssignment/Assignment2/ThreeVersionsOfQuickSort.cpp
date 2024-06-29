#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// 1. Naive Quick Sort Function
void naiveQuickSort(int arr[], int left, int right);
int partition(int arr[], int low, int high);

// 2. Randomized Quick Sort Function
void randomizedQuickSort(int arr[], int left, int right);
int medianOf3(int arr[], int low, int high);
int randomizedPartition(int arr[], int low, int high);

// 3. Tail-Recursive Quick Sort Function
void tailRecursiveQuickSort(int arr[], int low, int high);

// Write array to output file
void writeArray(int arr[], int size, ofstream& output_file);
// Swap elements of array
void swap(int* a, int* b);

int main(int argc, char *argv[]) {
    // Input stream
    ifstream input_file(argv[1]);
    // Output stream
    ofstream output_file(argv[2]);

    // Error handling
    if (!input_file.is_open() || !output_file.is_open()) {
        cout << "Cannot open the file" << endl;
        return 1;
    }

    int n;
    input_file >> n;

    int *originalArray = new int[n];
    int *arrayOfNaiveQuickSort = new int[n];
    int *arrayOfRandomizedQuickSort = new int[n];
    int *arrayOfTailRecursiveQuickSort = new int[n];

    for (int i = 0; i < n; ++i) {
        input_file >> originalArray[i];
        // Initializing 3 arrays to use in 3 different quick sort algorithm
        arrayOfNaiveQuickSort[i]=originalArray[i];
        arrayOfRandomizedQuickSort[i]=originalArray[i];
        arrayOfTailRecursiveQuickSort[i]=originalArray[i];
    }

    // Naive Quick sort
    naiveQuickSort(arrayOfNaiveQuickSort, 0, n-1);
    writeArray(arrayOfNaiveQuickSort, n, output_file);
    output_file << endl;

    // Randomized Quick Sort
    randomizedQuickSort(arrayOfRandomizedQuickSort, 0, n-1);
    writeArray(arrayOfRandomizedQuickSort, n, output_file);
    output_file << endl;

    // Tail-Recursive Quick Sort
    tailRecursiveQuickSort(arrayOfTailRecursiveQuickSort, 0, n-1);
    writeArray(arrayOfTailRecursiveQuickSort, n, output_file);

    // Resource deallocation
    input_file.close();
    output_file.close();

    delete[] originalArray;
    delete[] arrayOfNaiveQuickSort;
    delete[] arrayOfRandomizedQuickSort;
    delete[] arrayOfTailRecursiveQuickSort;

    return 0;
}

// 1. Naive Quick Sort
void naiveQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        naiveQuickSort(arr, low, pi - 1);
        naiveQuickSort(arr, pi + 1, high);
    }
}

// Partition Function of Naive Quick Sort, Tail-Recursive Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing last element as a pivot
    int i = (low - 1); // i is initialized to an index smaller than the smallest value in the array

    for (int j = low; j < high; j++) {
        // Just think of element <= pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap pivot element and (i+1) element
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 2. Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Partition of Randomized Quick Sort
int randomizedPartition(int arr[], int low, int high) {
    int pivotIndex = medianOf3(arr, low, high); // Choosing pivot by using Median-of-3 method
    int pivot = arr[pivotIndex];
    int i = low - 1;

    swap(&arr[pivotIndex], &arr[high]); // Swap elements of pivotIndex and high

    for (int j = low; j < high; j++) {
        // Just think of element <= pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap pivot element and (i+1) element
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Choosing pivot by using Median-of-3 method
int medianOf3(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // Finds the median by comparing the values of low and high
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    // return median
    return mid;
}

// 3. Tail-Recursive Quick Sort
void tailRecursiveQuickSort(int arr[], int low, int high) {
    while (low < high) {
        int pi = partition(arr, low, high);
        // Sorts the smaller subarray first, minimizing recursive calls
        if (pi - low < high - pi) {
            tailRecursiveQuickSort(arr, low, pi - 1);
            low = pi + 1;
        } else {
            tailRecursiveQuickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

// A function that swaps two elements of an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Write an array to output file
void writeArray(int arr[], int size, ofstream& output_file) {
    for (int i = 0; i < size; ++i) {
        output_file << arr[i];
        if (i != size - 1) {
            output_file << " ";
        }
    }
}