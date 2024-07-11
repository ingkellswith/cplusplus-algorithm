#include <iostream>
#include <vector>

using namespace std;

// 병합 함수
void merge(vector<int>& arr, int left, int mid, int right) {
    // left, mid, right는 인덱스를 의미하는데
    // 인덱스가 0,1,2,3,4,5,6,7일 경우 7/2=3이 된다
    // 따라서 n1은 +1을 해준다.
    // n1은 왼쪽 임시 배열의 크기
    int n1 = mid - left + 1;
    // n2는 오른쪽 임시 배열의 크기
    int n2 = right - mid;

    // 임시 배열들을 생성합니다.
    vector<int> L(n1), R(n2);

    // 데이터를 임시 배열로 복사합니다.
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남아있는 요소들을 복사합니다.
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 병합 정렬 함수
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right)  / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}