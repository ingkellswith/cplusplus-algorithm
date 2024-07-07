#include <iostream>
#include <vector>
#include <algorithm> // for swap

// ���� �����ϴ� �Լ�
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // ��Ʈ�� ���� ū ��ҷ� ����
    int left = 2 * i + 1; // ���� �ڽ�
    int right = 2 * i + 2; // ������ �ڽ�

    // ���� �ڽ��� ��Ʈ���� ū ���
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // ������ �ڽ��� ���� ū ��Һ��� ū ���
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // ���� ū ��Ұ� ��Ʈ�� �ƴ� ���
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // ��������� ������ �޴� ����Ʈ���� ��ȭ
        heapify(arr, n, largest);
    }
}

// �� ���� �Լ�
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // �ִ� ���� ����
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // �ϳ��� ��Ҹ� ������ ����
    for (int i = n - 1; i >= 0; i--) {
        // ���� ��Ʈ(���� ū ���)�� ������ �̵�
        std::swap(arr[0], arr[i]);
        // ���ҵ� ���� ��ȭ
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
