#include <iostream>
#include <vector>
#include <algorithm> // for make_heap, push_heap, pop_heap

int main() {
    std::vector<int> heap = {12, 11, 13, 5, 6, 7};

    // 힙을 만듭니다.
    std::make_heap(heap.begin(), heap.end());
    std::cout << "Heap after make_heap: ";
    for (const int& num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 새로운 요소를 힙에 추가합니다.
    heap.push_back(15);       // 1. 벡터의 끝에 새로운 요소를 추가
    std::push_heap(heap.begin(), heap.end());  // 2. 새로운 요소를 힙에 맞게 재배치
    std::cout << "Heap after push_heap: ";
    for (const int& num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 루트 요소를 제거합니다.
    std::pop_heap(heap.begin(), heap.end()); // 1. 힙에서 가장 큰 요소를 끝으로 이동
    heap.pop_back();        // 2. 실제로 배열에서 요소를 제거
    std::cout << "Heap after pop_heap: ";

    std::sort_heap(heap.begin(), heap.end());
    for (const int& num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
