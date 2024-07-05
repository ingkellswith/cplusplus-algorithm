## 1920 수 찾기
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
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); //A배열 정렬 O(nlogn)시간 복잡도

    cin >> M;
    for (int i = 0; i < M; i++) {
        bool find = false;
        int target;
        cin >> target;
        // 이진 탐색 시작
        int start = 0;
        int end = A.size() - 1;
        while (start <= end) {
            int midi = (start + end) / 2;
            int midV = A[midi];
            if (midV > target) {
                end = midi - 1;
            }
            else if (midV < target) {
                start = midi + 1;
            }
            else {
                find = true;
                break;
            }
        }
        if (find) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}
```

## 2343 기타 레슨
블루레이에 첫 레슨부터 마지막 레슨까지 차례대로 저장하다 보면 지정한 블루레이 크기로 모든 레슨을 저장할 수 있는지 판단할 수 있다.
모두 저장할 수 있다면 블루레이 크기를 줄이고 저장할 수 없다면 블루레이 크기를 늘린다.
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
    vector<int> A(N);
    int start = 0;
    int end = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (start < A[i]) {
            start = A[i]; // 레슨 최대값을 시작인덱스로 저장
        }
        end = end + A[i]; // 모든 레슨의 총 합을 종료 인덱스로 저장
    }

    while (start <= end) {
        int middle = (start + end) / 2;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < N; i++) { // middle값으로 모든 레슨을 저장 할 수 있는지 확인
            // 현재 블루레이에 저장할  수 없어 새로운 블루레이로 교체한다는 의미
            if (sum + A[i] > middle) {
                count++;
                sum = 0;
            }
            sum = sum + A[i];
        }
        if (sum != 0)
            count++;
        // 현재 중간 인덱스 값으로 모든 레슨 저장 불가
        if (count > M)
            start = middle + 1;
        else
            end = middle - 1;
    }
    cout << start << "\n";
}
```

## 1300 K번째 수
```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, K;
    cin >> N >> K;
    long start = 1, end = K;
    long ans = 0;
    // 이분 탐색 수행
    while (start <= end) {
        long middle = (start + end) / 2;
        long cnt = 0;
        // 중앙 값보다 작은 수는 몇 개인지 계산.
        for (int i = 1; i <= N; i++) {
            cnt += min(middle/i, N);  // 작은 수를 카운트하는 핵심로직
        }
        if (cnt < K) {
            start = middle + 1;
        }
        else {
            ans = middle;  // 현재 단계의 중앙 값을 정답 변수에 저장
            end = middle - 1;
        }
    }
    cout << ans << "\n";
}
```