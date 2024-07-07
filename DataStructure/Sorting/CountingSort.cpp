#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element, std::min_element

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // 배열의 최댓값과 최솟값을 찾습니다.
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());

    int range = max - min + 1;

    // 카운트 배열을 생성하고 초기화합니다.
    std::vector<int> count(range, 0);

    // 각 값의 출현 빈도를 계산합니다.
    for (int num : arr) {
        count[num - min]++;
    }

    // 누적 카운트를 계산합니다.
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 정렬된 배열을 생성합니다.
    std::vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // 정렬된 결과를 원래 배열에 복사합니다.
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
