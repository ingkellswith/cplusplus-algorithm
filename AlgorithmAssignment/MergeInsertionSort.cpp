#include <fstream>
#include <iostream>

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

    ifstream input_file(argv[1]);
    ofstream output_file(argv[2]);

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
        // initializing 3 arrays to use in 3 different sort algorithm
        arrayOfInsertion[i]=originalArray[i];
        arrayOfMerge[i]=originalArray[i];
        arrayOfMergeInsertion[i]=originalArray[i];
    }

    int k = 5; // The value of 'k' determines when to switch to Insertion Sort based on the size of the array.

    insertionSort(arrayOfInsertion, 0, n-1);
    writeArray(arrayOfInsertion, n, output_file);
    output_file << endl;

    mergeSort(arrayOfMerge, 0, n-1);
    writeArray(arrayOfMerge, n, output_file);
    output_file << endl;

    mergeInsertionSort(arrayOfMergeInsertion, 0, n - 1, k);
    writeArray(arrayOfMergeInsertion, n, output_file);

    // resource deallocation
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
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort Function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Using 'left + (right - left) / 2' is preferred over '(left + right) / 2' because calculating '(right - left) / 2' helps
        // prevent overflow issues when 'left' and 'right' are large numbers, although both expressions yield the same result in most cases.
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Merge Function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort와 Insertion Sort를 결합한 함수
void mergeInsertionSort(int arr[], int left, int right, int k) {
    if (left < right) {
        if (right - left + 1 <= k) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(arr, left, mid, k);
            mergeInsertionSort(arr, mid + 1, right, k);
            merge(arr, left, mid, right);
        }
    }
}

// Write array to output file
void writeArray(int arr[], int size, ofstream& output_file) {
    for (int i = 0; i < size; ++i) {
        output_file << arr[i];
        if (i != size - 1) {
            output_file << " ";
        }
    }
}