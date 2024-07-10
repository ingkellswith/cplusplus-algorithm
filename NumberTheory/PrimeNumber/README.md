# 1929 소수 구하기
에라토스테네스의 체를 사용해야 시간 복잡도를 줄일 수 있음
```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M  >> N;
    vector<int> A(N+1);
    
    // 에라토스테네스의 체 - 핵심 로직
    for (int i = 2; i <= N; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(N); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= N; j = j + i) { // 배수 지우기
            A[j] = 0;
        }
    }
    for (int i = M; i <= N; i++) {
        if (A[i] != 0) {
            cout << A[i] << "\n";
        }
    }
}
```

# 1456 거의 소수 구하기
```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long Min, Max;
    cin >> Min >> Max;
    long A[10000001];

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }
    for (int i = 2; i <=  sqrt(10000001); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j < 10000001; j = j + i) { // 배수 지우기
            A[j] = 0;
        }
    }
    int count = 0;
    for (int i = 2; i < 10000001; i++) {
        if (A[i] != 0) {
            long temp = A[i];
            // N^k, B값 비교가 아니라 N과 B/N^k-1을 비교해야 변수 표현 범위를 안 넘어갈 수 있음
            while ((double)A[i] <= (double)Max / (double)temp) {
                if ((double)A[i] >= (double)Min / (double)temp) {
                    count++;
                }
                temp = temp * A[i];
            }
        }
    }
    cout << count << "\n";
}
```

# 1747 소수 & 팰린드롬 수 중에서 최솟값 찾기
```c++
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
bool isPalindrome(int target);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    cin >> N;
    long A[10000001];

    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(10000001); i++) { // 제곱근 까지만 수행
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j < 10000001; j = j + i) { // 배수 지우기
            A[j] = 0;
        }
    }
    int i = N;
    while (true) { // N부터 1씩 증가시켜가면서 소수와 펠린드롬 수가 맞는지 확인
        if (A[i] != 0) {
            int result = A[i];
            if (isPalindrome(result)) {
                cout << result << "\n";
                break;
            }
        }
        i++;
    }
}

bool isPalindrome(int target) // 펠린드롬수 판별 함수
{
    string temp_str = to_string(target); //converting number to a string
    char const* temp = temp_str.c_str(); //converting string to char Array
    int s = 0;
    int e = temp_str.size() - 1;
    while (s < e) {
        if (temp[s] != temp[e])
            return false;
        s++;
        e--;
    }
    return true;
}
```

# 1016 제곱이 아닌 수 찾기
에라토스테네스의 체의 활용으로 시간 복잡도 최소화
```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long Min, Max;
    cin >> Min >> Max;
    // 최댓값과 최솟값의 차이 만큼 배열 선언
    vector<bool> Check(Max - Min + 1,0);
    // 2의 제곱수인 4부터 max보다 작거나 같은 수까지 반복
    for (long i = 2; i * i <= Max; i++) {
        long pow = i * i; // 제곱수
        long start_index = Min / pow;
        if (Min % pow != 0)
            start_index++; // 나머지가 있으면 1을 더해주어야 Min보다 큰 제곱수 부터 시작됨
        for (long j = start_index; pow * j <= Max; j++) { // 제곱수를 true로 변경
            Check[(int)((j * pow) - Min)] = true;
        }
    }
    int count = 0;
    for (int i = 0; i <= Max - Min; i++) {
        if (!Check[i]) {
            count++;
        }
    }
    cout << count << "\n";
}
```