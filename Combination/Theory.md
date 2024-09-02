# 순열
```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 팩토리얼을 계산하는 함수
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    int n = 5; // n개의 원소
    int r = 3; // r개를 선택

    // 순열의 개수 nPr = n! / (n-r)!
    int permutation_count = factorial(n) / factorial(n - r);
    cout << "Number of permutations (nPr): " << permutation_count << endl;

    // next_permutation을 이용한 순열 출력
    vector<int> v = {1, 2, 3};

    cout << "All permutations of {1, 2, 3}:" << endl;
    do {
        for (int num : v)
            cout << num << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
```

# 조합
```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 팩토리얼을 계산하는 함수
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    int n = 5; // n개의 원소
    int r = 3; // r개를 선택

    // 조합의 개수 nCr = n! / (r! * (n-r)!)
    int combination_count = factorial(n) / (factorial(r) * factorial(n - r));
    cout << "Number of combinations (nCr): " << combination_count << endl;

    // combination을 위한 벡터 초기화
    vector<int> v = {1, 2, 3, 4, 5};
    vector<bool> select(n, false);
    fill(select.begin(), select.begin() + r, true);

    cout << "All combinations of {1, 2, 3, 4, 5} choose 3:" << endl;
    do {
        for (int i = 0; i < n; ++i) {
            if (select[i]) {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    } while (prev_permutation(select.begin(), select.end()));

    return 0;
}

```