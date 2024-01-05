#include <iostream>

// 선택 정렬 함수
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;  // 최소값을 가진 요소의 인덱스

        // i 다음의 모든 요소를 검사하여 최소값을 찾음
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // 최소값을 가진 요소의 인덱스 업데이트
            }
        }

        // 현재 i번째 요소와 최소값을 가진 요소를 교환
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
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

    selectionSort(arr, n);

    std::cout << "Sorted array in ascending order: \n";
    printArray(arr, n);

    return 0;
}