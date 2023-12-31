#include <iostream>
#include <vector>
#include <algorithm>

// �� ���� �Լ�
void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // pivot�� �������� ����
        int pivotIndex = (left + right)  / 2;
        int pivotValue = arr[pivotIndex];

        // pivotValue�� �������� arr�� ����
        int i = left, j = right;
        while (i <= j) {
            // arr[i]�� pivotValue�� ���� �Ǹ� �ݺ����� �������� �����Ƿ� i�� pivotIndex�� ���� ���� ������ �� �̻��� �� ���� ����. j�� ������ �̿� ����.
            // ���ʿ��� �����ϴ� i�� pivotValue���� ū ù ��° ���Ҹ� ã�´�
            while (arr[i] < pivotValue) i++;
            // �����ʿ��� �����ϴ� j�� pivotValue���� ���� ù ��° ���Ҹ� ã�´�
            while (arr[j] > pivotValue) j--;
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // ��������� �� �κ� �迭�� ����
        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
}

int main() {
    std::vector<int> arr = { 3,8,7,2,5,1,4,6 };

    std::cout << "Before sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "After sorting: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}