#include <stdio.h>

// 함수 선언
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

// 메인 함수
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("before sorting : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, n - 1);
    printf("after sorting : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// 퀵소트 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pivot을 기준으로 배열을 분할
        int pi = partition(arr, low, high);

        // pivot을 기준으로 분할된 두 부분에 대해 퀵소트 호출
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 분할 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot을 마지막 요소로 선택
    int i = (low - 1); // pivot보다 작은 요소들을 추적하기 위한 인덱스

    for (int j = low; j <= high - 1; j++) {
        // 현재 요소가 pivot보다 작으면,
        // 작은 요소들을 swap하고 인덱스를 증가시킴
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // pivot보다 작은 요소들을 모두 swap한 후에 pivot을 올바른 위치에 놓음
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 요소들을 바꾸는 함수
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}