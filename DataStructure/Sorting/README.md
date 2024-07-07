# 2750 수 정렬하기 - 버블 정렬
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
  
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }
}
```

# 1377 버블 정렬 프로그램1 - 버블 정렬

코드 자체는 간단하지만 아이디어를 모르면 풀 수 없는 문제, 테스트 케이스 여러 개를 직접 계산해봐야 규칙 도출 가능
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end()); //A배열 정렬 O(nlogn)시간 복잡도

    int Max = 0;
    for (int i = 0; i < N; i++) {
        if (Max < A[i].second - i) //정렬 전 index - 정렬 후 index 계산 값의 최대 값을 찾아 저장
            Max = A[i].second - i;
    }
    cout << Max + 1;
}
```

# 1427 소트인사이드 - 선택 정렬
```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> A(str.size(), 0);
    for (int i = 0; i < str.size(); i++) {
        A[i] = stoi(str.substr(i, 1));
    }

    for (int i = 0; i < str.length(); i++) {
        int Max = i;
        for (int j = i + 1; j < str.length(); j++) {
            if (A[j] > A[Max])  //내림차순이므로 최대 값을 찾음
                Max = j;
        }
        if (A[i] < A[Max]) {
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
   
}
```

STL 사용한 버전
```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    // vector<int> A(str.size()); 도 가능
    vector<int> A(str.size(),0);
    for (int i = 0; i < str.size(); i++) {
        A[i] = stoi(str.substr(i, 1));
    }

    // 내림차순 정렬
    sort(A.begin(), A.end(), greater<int>());

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }

    return 0;
}
```

# 11399 ATM - 삽입 정렬
역시 STL 사용 가능
```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr, int n) {
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

    return arr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<int> S(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    A=insertionSort(A,N);

    S[0] = A[0]; //합배열 만들기
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    int sum = 0; //합배열 총합 구하기
    for (int i = 0; i < N; i++) {
        sum = sum + S[i];
    }

    cout << sum;

}
```

# 11004 K번째 수 구하기 - 퀵 정렬
STL 사용 가능
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void quickSort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    quickSort(A, 0, N-1, K-1);
    cout << A[K - 1];
}

void quickSort(vector<int> &A, int S, int E, int K) {
    int pivot = partition(A, S, E);
    if (pivot == K)// K번째 수가 pivot이면 더이상 구할 필요 없음
        return;
    else if (K < pivot) // K가 pivot보다 작으면 왼쪽 그룹만 정렬 수행하기
        quickSort(A, S, pivot - 1, K);
    else // K가 pivot보다 크면 오른쪽 그룹만 정렬 수행하기
        quickSort(A, pivot + 1, E, K);
}
int partition(vector<int> &A, int S, int E) {
    if (S + 1 == E) {
        if (A[S] > A[E])swap(A, S, E);
        return E;
    }
    int M = (S + E) / 2;
    swap(A, S, M); // 중앙값을 1번째 요소로 이동하기
    int pivot = A[S];
    int i = S + 1, j = E;
    while (i <= j) {
        while (j >= S + 1 && pivot < A[j]) {   //피벗보다 작은 수가 나올때까지 j--
            j--;
        }
        while (i <= E && pivot > A[i] ) {  //피벗보다 큰 수가 나올 까지 i++
            i++;
        }

        if (i < j) {
            swap(A, i++, j--);  // 찾은 i와 j를 교환하기
        }
        else {
            break;
        }
    }
    // i == j 피벗의 값을 양쪽으로 분리한 가운데에 오도록 설정하기
    A[S] = A[j];
    A[j] = pivot;
    return j;
}
void swap(vector<int> &A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
```

결과값 정답, 시간초과 풀이
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void quickSort(vector<int> &A, int S, int E);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);
int medianOf3(vector<int> &A, int low, int high);
void tailRecursiveQuickSort(vector<int> &A, int low, int high);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    tailRecursiveQuickSort(A, 0, N-1);
    cout << A[K - 1];
}

void tailRecursiveQuickSort(vector<int> &arr, int low, int high) {
    while (low < high) {
        int pi = partition(arr, low, high);
        // Sorts the smaller subarray first, minimizing recursive calls
        if (pi - low < high - pi) {
            tailRecursiveQuickSort(arr, low, pi - 1);
            low = pi + 1;
        } else {
            tailRecursiveQuickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

void quickSort(vector<int> &A, int S, int E) {
    if(S<E){
        int pivot = partition(A, S, E);
        quickSort(A, S, pivot - 1);
        quickSort(A, pivot + 1, E);
    }
}

int partition(vector<int> &arr, int low, int high) {
    int pivotIndex = medianOf3(arr, low, high); // Choosing pivot by using Median-of-3 method
    int pivot = arr[pivotIndex];
    int i = low - 1;

    swap(arr,pivotIndex,high); // Swap elements of pivotIndex and high

    for (int j = low; j < high; j++) {
        // Just think of element <= pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr,i,j);
        }
    }
    // Swap pivot element and (i+1) element
    swap(arr,i + 1, high);
    return (i + 1);
}

void swap(vector<int> &A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int medianOf3(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    // Finds the median by comparing the values of low and high
    if (arr[low] > arr[mid])
        swap(arr,low,mid);
    if (arr[low] > arr[high])
        swap(arr,low,high);
    if (arr[mid] > arr[high])
        swap(arr,mid,high);

    // return median
    return mid;
}
```

# 2751 수 정렬하기 2 -병합 정렬
STL 사용 가능
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> A;
void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    mergeSort(A,0, N-1); // 병합정렬 수행하기

    for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
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
void mergeSort(vector<int>& arr, int left, int right) {
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
```

# 1517 버블정렬 프로그램 2 -병합 정렬
손으로 풀어보면서 아이디어 도출해내야 함
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> A;
static long result;
void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    result = 0;
    mergeSort(A,0, N-1); // 병합정렬 수행하기
    cout << result << "\n";
}

void merge(vector<int>& arr, int left, int mid, int right) {
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
    int tmp = mid+1;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            result = result + (tmp-k);
            arr[k] = R[j];
            j++;
            tmp++;
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
void mergeSort(vector<int>& arr, int left, int right) {
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
```

# 10989 수 정렬하기3 - 기수 정렬(radix sort)
기수 정렬, 계수 정렬의 핵심은 원본 array의 값이 count array의 index가 된다는 것이다.
ex) `output[count[arr[i] - min] - 1] = arr[i];`
```c++
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int count[10001] = { 0 };
    int number = 0;
    for (int i = 1; i <= N; i++) {
        cin >> number;
        count[number]++;
    }
    for (int i = 0; i <= 10000; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {    // 해당 count 배열의 값 만큼 index를 반복하여 출력
                cout << i << "\n";  
            }
        }
    }
}
```