#include <iostream>
#include <algorithm>
#include <vector>

void heapSort(std::vector<int>& arr) {
    // ���� ���� - arr�� ���� �ȴ�
    std::make_heap(arr.begin(), arr.end());

    // �Ʒ� �ݺ����� �������� ������ �������� ����
    // ������ ���� ū ���� ����ؼ� �����鼭 ����
    for (int i = 0; i < arr.size()-1; i++) {
        // ���� �ִ밪(��Ʈ)�� �迭�� ���������� ����
        // arr.begin() + i + 1�� ���������� �׷��� ������ ���δ�.
        std::pop_heap(arr.begin(), arr.end()-i);

        // ���� �ִ밪�� �迭�� ���κп� ��ġ (���ĵ� �κ����� ���)
        // ���� arr[i]�� ���ĵ� ���¸� ������ ����
        // pop_heap�� ���� �ִ밪�� �迭�� ���κп� ��ġ�ϰ�, pop_back�� �׳� pop�Ѵ�.
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