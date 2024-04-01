#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    // 배열의 각 요소를 순회하며 최소값을 선택하여 정렬
    for (i = 0; i < n-1; i++) {
        // 현재 인덱스를 최소값으로 가정
        min_idx = i;
        // 현재 인덱스 다음의 요소들과 비교하여 최소값을 찾음
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // 최소값을 현재 위치로 이동
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("before sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n);

    printf("after sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}