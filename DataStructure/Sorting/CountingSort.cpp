#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element, std::min_element

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // �迭�� �ִ񰪰� �ּڰ��� ã���ϴ�.
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());

    int range = max - min + 1;

    // ī��Ʈ �迭�� �����ϰ� �ʱ�ȭ�մϴ�.
    std::vector<int> count(range, 0);

    // �� ���� ���� �󵵸� ����մϴ�.
    for (int num : arr) {
        count[num - min]++;
    }

    // ���� ī��Ʈ�� ����մϴ�.
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // ���ĵ� �迭�� �����մϴ�.
    std::vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // ���ĵ� ����� ���� �迭�� �����մϴ�.
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
