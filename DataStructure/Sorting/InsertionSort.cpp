#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    // 배열을 순회하면서 삽입 정렬 수행
    for (i = 1; i < n; i++) {
        key = arr[i]; // 현재 비교할 값 저장, i가 key index가 됨
        j = i - 1;
        // 이후로 i를 사용하지 않음
        // 현재 비교할 값(key)을 이미 정렬된 배열 부분에 삽입
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("before sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    insertionSort(arr, n);

    printf("after sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}