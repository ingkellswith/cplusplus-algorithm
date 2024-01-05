#include <iostream>

// 삽입 정렬 함수
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // key보다 큰 모든 요소를 오른쪽으로 이동 - 정렬 영역 : key 인덱스 이하
        // index가 0보다 커야 함
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 배열 요소를 출력하는 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: \n";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted array in ascending order: \n";
    printArray(arr, n);

    return 0;
}