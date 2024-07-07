#include <iostream>
#include <vector>
#include <algorithm> // for swap

// 힙을 구성하는 함수
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // 루트를 가장 큰 요소로 가정
    int left = 2 * i + 1; // 왼쪽 자식
    int right = 2 * i + 2; // 오른쪽 자식

    // 왼쪽 자식이 루트보다 큰 경우
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 오른쪽 자식이 가장 큰 요소보다 큰 경우
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 가장 큰 요소가 루트가 아닌 경우
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // 재귀적으로 영향을 받는 서브트리를 힙화
        heapify(arr, n, largest);
    }
}

// 힙 정렬 함수
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // 최대 힙을 구성
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 하나씩 요소를 힙에서 추출
    for (int i = n - 1; i >= 0; i--) {
        // 현재 루트(가장 큰 요소)를 끝으로 이동
        std::swap(arr[0], arr[i]);
        // 감소된 힙을 힙화
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
