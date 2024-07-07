#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

// 특정 자릿수에 대해 Counting Sort 수행
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); // 정렬된 배열을 저장할 임시 배열
    int count[10] = {0}; // 카운트 배열 (0-9 범위)

    // 출현 빈도 계산
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 누적 카운트 계산
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 정렬된 배열 생성
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // 정렬된 결과를 원래 배열에 복사
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort 구현
void radixSort(std::vector<int>& arr) {
    // 배열의 최대값을 찾음
    int max = *std::max_element(arr.begin(), arr.end());

    // 1의 자리부터 시작해서 각 자릿수에 대해 Counting Sort 수행
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
