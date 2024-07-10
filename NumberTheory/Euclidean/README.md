# 1934 최소 공배수 구하기
```c++
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int result = a * b / gcd(a, b);
        cout << result << "\n";
    }
}

// a가 큰 수이든 작은 수이든 상관 없이 재귀적으로 구현하면 유클리드 호제법을 구현한 셈
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);   // 재귀함수 형태로 구현
}
```

# 1850 최대 공약수 구하기
2 -> 111, 3 -> 1111로 10진수의 값이 n개의 1로 표현됨
```c++
#include <iostream>
#include <cmath>
using namespace std;

int gcd(long a, long b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long a, b;
    cin >> a >> b;
    long result = gcd(a, b);
    while (result > 0) {
        cout << 1;
        result--;
    }
    cout << '\n';
}

int gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
```

# 1033 칵테일 만들기
```c++
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


vector<tuple<int, int, int>> A[10];
long lcm;
bool visited[10];
long D[10];

long gcd(long a, long b);
void DFS(int node);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    lcm = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));
        lcm *= (p * q / gcd(p, q)); // 두 수의 최소 공배수는 두수의 곱을 최대 공약수로 나눈 것입니다.
    }
    D[0] = lcm;
    DFS(0);
    long mgcd = D[0];
    for (int i = 1; i < N; i++) {
        mgcd = gcd(mgcd, D[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << D[i] / mgcd << ' ';
    }
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void DFS(int node) { // DFS구현
    visited[node] = true;
    for (tuple<int, int, int> i : A[node]) {
        int next = get<0>(i);
        if (!visited[next]) {
            D[next] = D[node] * get<2>(i) / get<1>(i); //주어진 비율로 다음 노드 값 업데이트
            DFS(next);
        }
    }
}
```