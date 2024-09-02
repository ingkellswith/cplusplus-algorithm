# 11050 이항계수 구하기 1
```c++
#include <iostream>
using namespace std;

static int N, K;
static int D[11][11];

int main()
{
	cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
        }
    }
	cout << D[N][K] << "\n";
}
```

# 11051 이항계수 구하기 2
```c++
#include <iostream>
using namespace std;

static int N, K;
static int D[1001][1001];

int main()
{
    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
            D[i][j] = D[i][j] % 10007;
        }
    }
    cout << D[N][K] << "\n";
}
```

# 2775 부녀회장이 될테야
```c++
#include <iostream>
using namespace std;

static int T, N, K;
static int D[15][15];

int main()
{
    for (int i = 0; i < 15; i++) { //초기화
        D[i][1] = 1;
        D[0][i] = i;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            D[i][j] = D[i][j - 1] + D[i - 1][j];  // 점화식
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++) // D배열을 모두 구해놓은 후 질의 출력
    {
        cin >> K >> N;
        cout << D[K][N] << "\n";
    }
}
```

# 1010 다리놓기
```c++
#include <iostream>
using namespace std;

static int T, N, M;
static int D[31][31];

int main()
{
    for (int i = 0; i <= 30; i++) {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
        }
    }
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << D[M][N] << "\n";
    }
}
```

# 13251 조약돌 꺼내기
```c++
#include <iostream>
using namespace std;

static int M, K, T;
static int D[51];
static double probability[51];
static double ans = 0.0;

int main()
{
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> D[i];
        T += D[i];
    }

    cin >> K;
    for (int i = 0; i < M; i++) {
        if (D[i] >= K) {
            probability[i] = 1.0;
            for (int k = 0; k < K; k++)
                probability[i] *= (double)(D[i] - k) / (T - k);
        }
        ans += probability[i];
    }
    cout << fixed;
    cout.precision(9); // 오차 범위내 출력을 위한 소수점 자리수 설정
    cout << ans;
}
```

# 1722 순열의 순서
```c++
#include <iostream>
using namespace std;

static int N, Q;
static long F[21], S[21];
static bool visited[21] = {false};

int main()
{
    cin >> N >> Q;
    F[0] = 1;
    for (int i = 1; i <= N; i++) { // 팩토리얼 초기화 -> 각 자리수에서 만들수 있는 경우의 수
        F[i] = F[i - 1] * i;
    }
    if (Q == 1) {
        long K;
        cin >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 1, cnt = 1; j <= N; j++) {
                if (visited[j])
                    continue; // 이미 사용한 숫자는 사용할 수 없음
                if (K <= cnt * F[N - i]) { // 주어진 K에 따라 각 자리에 들어갈 수 있는 수 찾기
                    K -= ((cnt - 1) * F[N - i]);
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }
        for (int i = 1; i <= N; i++) {
            cout << S[i] << " ";
        }
    }
    else {
        long K = 1;
        for (int i = 1; i <= N; i++) {
            cin >> S[i];
            long cnt = 0;
            for (int j = 1; j < S[i]; j++) {
                if (visited[j] == false) {
                    cnt++; // 미사용 숫자 개수만큼 카운트
                }
            }
            K += cnt * F[N - i]; // 자리수 개수에 따라 순서 더해주기
            visited[S[i]] = true;
        }
        cout << K << "\n";
    }
}
```