# 11047 동전 개수의 최소값 구하기
```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] <= K) {    // 현재 동전의 가치가 K보다 작거나 같으면 구성에 추가.
            count += (K / A[i]);
            K = K % A[i];   // K를 현재 동전을 사용하고 남은 금액으로 업데이트 함
        }
    }

    cout << count << "\n";
}
```

# 1715 카드 정렬하기
```c++
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int,vector<int>, greater<int>> pq;   // 오름차순 정렬

    int data;
    for (int i = 0; i < N; i++) {
        cin >> data;
        pq.push(data);
    }
    int data1 = 0;
    int data2 = 0;
    int sum = 0;
    while (pq.size() != 1) {
        data1 = pq.top();
        pq.pop();
        data2 = pq.top();
        pq.pop();
        sum += data1 + data2;
        pq.push(data1 + data2);
    }

    cout << sum << "\n";
}
```

# 1744 수 묶기
```c++
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int> plusPq;                               // 내림차순 정렬
    priority_queue<int, vector<int>, greater<int>> minusPq;   // 오름차순 정렬

    int one = 0;
    int zero = 0;
    for (int i = 0; i < N; i++) { // 4개의 그룹으로 분리하여 저장
        int data;
        cin >> data;
        if (data > 1) {
            plusPq.push(data);
        }
        else if (data == 1) {
            one++;
        }
        else if (data == 0) {
            zero++;
        }
        else {
            minusPq.push(data);
        }
    }
    int sum = 0;
    // 양수처리
    while (plusPq.size() > 1) {
        int first = plusPq.top();
        plusPq.pop();
        int second = plusPq.top();
        plusPq.pop();
        sum = sum + first * second;
    }
    if (!plusPq.empty()) {
        sum = sum + plusPq.top();
        plusPq.pop();
    }
    // 음수처리
    while (minusPq.size() > 1) {
        int first = minusPq.top();
        minusPq.pop();
        int second = minusPq.top();
        minusPq.pop();
        sum = sum + first * second;
    }
    if (!minusPq.empty()) {
        if (zero == 0) {
            sum = sum + minusPq.top();
            minusPq.pop();
        }
    }
    // 1처리
    sum = sum + one;

    cout << sum << "\n";
}
```

# 1931 회의실 배정하기
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

    for (int i = 0; i < N; i++) {   // 종료 시간 정렬 우선을 위해 종료 값을 first에 저장
        cin >> A[i].second;
        cin >> A[i].first;
    }
    
    sort(A.begin(), A.end());

    int count = 0;
    int end = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].second >= end) { // 겹치지 않는 다음 회의가 나온경우
            end = A[i].first; // 종료시간 업데이트
            count++;
        }
    }
    cout << count << "\n";
}
```

# 1541 최솟값을 만드는 괄호 배치 찾기
```c++
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> split(string input, char delimiter);
int mySum(string a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');
    for (int i = 0; i < str.size(); i++) {
        int temp = mySum(str[i]);
        if (i == 0)
            answer = answer + temp; // 제일 앞에 것만 더해주고
        else
            answer = answer - temp; // 뒤에 부분은 더한 값들을 빼줌
    }

    cout << answer << "\n";
}

// c++에서는 split을 직접 구현해야 함
vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter)) {
        result.push_back(splitdata);
    }

    return result;
}

int mySum(string a) { // 나눠진 그룹의 더하기 연산 수행 함수
    int sum = 0;
    vector<string> temp = split(a, '+');
    for (int i = 0; i < temp.size(); i++) {
        sum += stoi(temp[i]);
    }
    return sum;
}
```