#include <stdio.h>

// 병합 함수
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    int L[n1], R[n2];

    // 왼쪽 부분 배열 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // 오른쪽 부분 배열 복사
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 두 부분 배열을 정렬하여 합병
    i = 0;
    j = 0;
    k = left;
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

    // 남은 요소들 복사
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
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 중간 지점 계산
        int mid = left + (right - left) / 2;

        // 왼쪽 부분 배열 정렬
        mergeSort(arr, left, mid);

        // 오른쪽 부분 배열 정렬
        mergeSort(arr, mid + 1, right);

        // 정렬된 두 부분 배열 병합
        merge(arr, left, mid, right);
    }
}

// 배열 출력 함수
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}