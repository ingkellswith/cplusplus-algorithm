#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

// Ư�� �ڸ����� ���� Counting Sort ����
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); // ���ĵ� �迭�� ������ �ӽ� �迭
    int count[10] = {0}; // ī��Ʈ �迭 (0-9 ����)

    // ���� �� ���
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // ���� ī��Ʈ ���
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // ���ĵ� �迭 ����
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // ���ĵ� ����� ���� �迭�� ����
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort ����
void radixSort(std::vector<int>& arr) {
    // �迭�� �ִ밪�� ã��
    int max = *std::max_element(arr.begin(), arr.end());

    // 1�� �ڸ����� �����ؼ� �� �ڸ����� ���� Counting Sort ����
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
