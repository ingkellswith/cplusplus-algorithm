#include <iostream>
#include <algorithm>
#include <vector>

void heapSort(std::vector<int>& arr) {
    // 赛阑 备己 - arr捞 赛捞 等促
    std::make_heap(arr.begin(), arr.end(), std::greater<int>{});
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}