#include <iostream>
#include <vector>
#include <algorithm>

// 퀵 정렬 함수
void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // pivot을 기준으로 분할
        int pivotIndex = (left + right)  / 2;
        int pivotValue = arr[pivotIndex];

        // pivotValue을 기준으로 arr를 분할
        int i = left, j = right;
        while (i <= j) {
            // arr[i]와 pivotValue가 같게 되면 반복문을 실행하지 않으므로 i는 pivotIndex와 같을 수는 있으나 그 이상이 될 수는 없다. j도 원리는 이와 동일.
            // 왼쪽에서 시작하는 i로 pivotValue보다 큰 첫 번째 원소를 찾는다
            while (arr[i] < pivotValue) i++;
            // 오른쪽에서 시작하는 j로 pivotValue보다 작은 첫 번째 원소를 찾는다
            while (arr[j] > pivotValue) j--;
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // 재귀적으로 각 부분 배열을 정렬
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