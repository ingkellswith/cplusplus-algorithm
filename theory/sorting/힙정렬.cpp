#include <iostream>
#include <algorithm>
#include <vector>

void heapSort(std::vector<int>& arr) {
    // 힙을 구성 - arr이 힙이 된다
    std::make_heap(arr.begin(), arr.end());

    // 아래 반복문을 실행하지 않으면 내림차순 정렬
    // 힙에서 가장 큰 값을 계속해서 꺼내면서 정렬
    for (int i = 0; i < arr.size()-1; i++) {
        // 힙의 최대값(루트)를 배열의 마지막으로 보냄
        // arr.begin() + i + 1는 문법적으로 그러한 듯으로 보인다.
        std::pop_heap(arr.begin(), arr.end()-i);

        // 꺼낸 최대값을 배열의 끝부분에 배치 (정렬된 부분으로 취급)
        // 이제 arr[i]는 정렬된 상태를 가지고 있음
        // pop_heap은 꺼낸 최대값을 배열의 끝부분에 배치하고, pop_back은 그냥 pop한다.
    }
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