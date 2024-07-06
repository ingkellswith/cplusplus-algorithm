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
            // i++, j-- 둘 중 하나만 있어도 됨 > 2018 참고
            i++;
            j--;
        }
    }
    cout << count << "\n";
}
```
## 원리
start_index, end_index를 양쪽 끝 인덱스에 위치시킨 후 각 포인터 이동


# 1253 '좋은 수' 구하기
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
    sort(A.begin(), A.end());
    int Result = 0;
    // 1. N개의 수만큼 반복
    for (int k = 0; k < N; k++) {
        // 2. 양쪽 끝을 인덱스로 하는 투 포인터 알고리즘
        long find = A[k];
        int i = 0;
        int j = N - 1;
        while (i < j) {  
            if (A[i] + A[j] == find) {  // 서로 다른 두 수의 합인지 체크
                if (i != k && j != k) {
                    Result++;
                    break;
                }
                // 값은 정수라는 조건이 있기에 음수가 될 수 있고, 중복이 가능하기에 아래 else if문을 꼭 써줘야 한다. ex) 0 0 0 0
                // 여기에서 '다른 수'라 함은 값이 같아도 인덱스가 다르면 다른 수로 취급한다.
                // 예를 들어, 0 0 0 에서 세 개의 다른 수가 있는 것이다.
                else if (i == k) {
                    i++;
                }
                // j도 마찬가지의 논리
                else if (j == k) {
                    j--;
                }
            }
            else if (A[i] + A[j] < find) {
                i++;
            }
            else {
                j--;
            }
        }
    }
    cout << Result << "\n";
}
```
## 원리
투 포인터를 사용하여 시간 복잡도를 n^2으로 만들어 풀 수 있다.