# 11689 오일러 피 함수 구현하기
풀이하면 서로소의 개수를 구하는 과정이다.
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

    long n;
    cin >> n;
    long result = n;
    for (long p = 2; p <= sqrt(n); p++) { // 제곱근까지만 진행
        if (n % p == 0) { // p가 소인수인지 확인
            result = result - result / p; // 결과 값 업데이트
            // case 4
            // result = 45 - 45/3 = 30
            // n = 45 / 3^2 = 5
            while (n % p == 0) { // 해당 소인수를 지워줌 2^7*11이라면 2^7을 없애고 11만 남김
                n /= p; // case 4에서 p=4이면 sqrt(5)보다 크므로 반복문 종료
            }
        }
    }
    // 30 - (30 / 5) = 24
    if (n > 1) { // n이 1보다 크면 n이 마지막 소인수라는 뜻
        //(반복문에서 제곱근까지만 탐색했기 때문에 1개의 소인수가 누락되는 케이스)
        result = result - result / n;
    }
    cout << result << "\n";
}
```
