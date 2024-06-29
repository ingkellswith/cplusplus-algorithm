#include <iostream>
#include <fstream>

using namespace std;

// Insertion Sort Function
void insertionSort(int arr[], int left, int right);

// Merge Sort Function
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// Merge + Insertion Sort Function
void mergeInsertionSort(int arr[], int left, int right, int k);

// Write array to output file
void writeArray(int arr[], int size, ofstream& output_file);

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
    int *arrayOfInsertion = new int[n];
    int *arrayOfMerge = new int[n];
    int *arrayOfMergeInsertion = new int[n];

    for (int i = 0; i < n; ++i) {
        input_file >> originalArray[i];
        // Initializing 3 arrays to use in 3 different sort algorithm
        arrayOfInsertion[i]=originalArray[i];
        arrayOfMerge[i]=originalArray[i];
        arrayOfMergeInsertion[i]=originalArray[i];
    }

    int k = 5; // The value of 'k' determines when to switch to Insertion Sort based on the size of the array.

    // Insertion sort
    insertionSort(arrayOfInsertion, 0, n-1);
    writeArray(arrayOfInsertion, n, output_file);
    output_file << endl;

    // Merge sort
    mergeSort(arrayOfMerge, 0, n-1);
    writeArray(arrayOfMerge, n, output_file);
    output_file << endl;

    // Merge + Insertion sort
    mergeInsertionSort(arrayOfMergeInsertion, 0, n - 1, k);
    writeArray(arrayOfMergeInsertion, n, output_file);

    // Resource deallocation
    input_file.close();
    output_file.close();

    delete[] originalArray;
    delete[] arrayOfInsertion;
    delete[] arrayOfMerge;
    delete[] arrayOfMergeInsertion;

    return 0;
}

// Insertion Sort Function
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        // Store the current element in a variable key
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert the key into its correct position in the sorted subarray
        arr[j + 1] = key;
    }
}

// Merge Sort Function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Using 'left + (right - left) / 2' is preferred over '(left + right) / 2' because calculating '(right - left) / 2' helps
        // prevent overflow issues when 'left' and 'right' are large numbers, although both expressions yield the same result in most cases.
        int mid = left + (right - left) / 2;
        // Recursively apply mergeSort to the left half of the subarray
        mergeSort(arr, left, mid);
        // Recursively apply mergeSort to the right half of the subarray
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Merge Function
void merge(int arr[], int left, int mid, int right) {
    // Calculate the sizes of the two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the elements of the two subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]

    // Initial indices of the first and second subarrays
    int i = 0, j = 0;
    // Initial index of the merged subarray
    int k = left;
    // Merge the two subarrays back into the original array arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge + Insertion sort
void mergeInsertionSort(int arr[], int left, int right, int k) {
    // Check if there are elements in the subarray
    if (left < right) {
        // If the size of the subarray is less than or equal to the threshold k, use insertion sort
        if (right - left + 1 <= k) {
            // Apply insertion sort to the subarray
            insertionSort(arr, left, right);
        } else {
            // Calculate the midpoint of the subarray
            int mid = left + (right - left) / 2;
            // Recursively apply mergeInsertionSort to the left half of the subarray
            mergeInsertionSort(arr, left, mid, k);
            // Recursively apply mergeInsertionSort to the right half of the subarray
            mergeInsertionSort(arr, mid + 1, right, k);
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }
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