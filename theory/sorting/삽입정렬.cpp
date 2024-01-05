#include <iostream>

// ���� ���� �Լ�
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // key���� ū ��� ��Ҹ� ���������� �̵� - ���� ���� : key �ε��� ����
        // index�� 0���� Ŀ�� ��
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// �迭 ��Ҹ� ����ϴ� �Լ�
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: \n";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted array in ascending order: \n";
    printArray(arr, n);

    return 0;
}