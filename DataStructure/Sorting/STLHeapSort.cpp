#include <iostream>
#include <vector>
#include <algorithm> // for make_heap, push_heap, pop_heap

int main() {
    std::vector<int> heap = {12, 11, 13, 5, 6, 7};

    std::make_heap(heap.begin(), heap.end());
    std::cout << "Heap after make_heap: ";
    for (const int& num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heap.push_back(15);
    std::push_heap(heap.begin(), heap.end());
    std::cout << "Heap after push_heap: ";
    for (const int& num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::pop_heap(heap.begin(), heap.end());
    heap.pop_back();
    std::cout << "Heap after pop_heap: ";

    std::sort_heap(heap.begin(), heap.end());
    for (const int& num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
