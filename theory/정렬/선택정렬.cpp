#include <iostream>

// ���� ���� �Լ�
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;  // �ּҰ��� ���� ����� �ε���

        // i ������ ��� ��Ҹ� �˻��Ͽ� �ּҰ��� ã��
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // �ּҰ��� ���� ����� �ε��� ������Ʈ
            }
        }

        // ���� i��° ��ҿ� �ּҰ��� ���� ��Ҹ� ��ȯ
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
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

    selectionSort(arr, n);

    std::cout << "Sorted array in ascending order: \n";
    printArray(arr, n);

    return 0;
}