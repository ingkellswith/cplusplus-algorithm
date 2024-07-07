#include <iostream>
#include <vector>
#include <climits> // for INT_MIN

class MaxHeap {
private:
    std::vector<int> heap;

    void heapify_down(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i) {
        if (i && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            heapify_up((i - 1) / 2);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;
        heapify_up(index);
    }

    void increase_key(int i, int new_val) {
        if (new_val < heap[i]) {
            std::cerr << "New value is smaller than current value." << std::endl;
            return;
        }

        heap[i] = new_val;
        heapify_up(i);
    }

    int extract_max() {
        if (heap.size() == 0) {
            std::cerr << "Heap is empty." << std::endl;
            return INT_MIN;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify_down(0);

        return root;
    }

    void print_heap() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);

    std::cout << "Heap after insertion: ";
    h.print_heap();

    std::cout << "Extracted max: " << h.extract_max() << std::endl;
    std::cout << "Heap after extracting max: ";
    h.print_heap();

    h.increase_key(2, 50);
    std::cout << "Heap after increasing key at index 2 to 50: ";
    h.print_heap();

    return 0;
}
