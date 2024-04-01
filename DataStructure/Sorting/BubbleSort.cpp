#include <stdio.h>

// c++인데 c언어만 사용
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // 마지막 i개의 원소는 이미 정렬되어 있으므로 제외
        for (j = 0; j < n-i-1; j++) {
            // 현재 원소가 다음 원소보다 크면 교환
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("before sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bubbleSort(arr, n);

    printf("after sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// best case에 O(n)이 되려면 이렇게 해야 함
// https://stackoverflow.com/questions/57245641/explanation-of-best-case-of-bubble-sort-being-on-and-not-on2 참고
//boolean previousIterationSwap = false;
//final int[] A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//for (int i = 0; i < A.length - 1; i++) {
//// After the first iteration check if previous iteration had any
//// swap
//if (i > 0 && !previousIterationSwap) {
//break;
//}
//for (int j = 0; j < A.length - i - 1; j++) {
//if (A[j] > A[j + 1]) {
//previousIterationSwap = true;
//final int temp = A[j];
//A[j] = A[j + 1];
//A[j + 1] = temp;
//} else {
//previousIterationSwap = false;
//}
//}
//}