투 포인터
===
투 포인터는 2개의 포인터로 알고리즘의 시간 복잡도를 최적화한다.

# 2018 연속된 자연수의 합 구하기
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
    int count = 1;
    int start_index = 1;
    int end_index = 1;
    int sum = 1;
    // end_index != N이 조건인 이유는 count가 이미 1이므로 N 그 자체를 셀 필요가 없기 때문
    while (end_index != N) {
        if (sum == N) {       // 답을 찾은 경우
            count++;
            end_index++;
            sum = sum + end_index;
        }
        else if (sum > N) {   // 현재 합이 답보다 큰 경우
            sum = sum - start_index;
            start_index++;
        }
        else {                // 현재 합이 답보다 작은 경우
            end_index++;
            sum = sum + end_index;
        }
    }
	cout << count << "\n";
}
```
## 원리
start_index, end_index를 처음 인덱스에 위치시킨 후 각 포인터 이동


# 1940 주몽의 명령
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

    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int count = 0;
    int i = 0;
    int j = N - 1;
    while (i < j) {
        if (A[i] + A[j] < M) {
            i++;
        }
        else if (A[i] + A[j] > M) {
            j--;
        }
        else {
            count++;
            i++;
            j--;
        }
    }
    cout << count << "\n";
}
```
## 원리
start_index, end_index를 양쪽 끝 인덱스에 위치시킨 후 각 포인터 이동
