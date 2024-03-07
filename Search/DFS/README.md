## 11724 연결요소의개수
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector < vector <int> > A;
static vector<bool> visited;
void DFS(int v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);


    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e ;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    int count = 0;
    for (int i = 1; i < N + 1; i++) {
        if (!visited[i]) { // 미 방문한 노드가 없을 때까지 반복
            count++;
            DFS(i);
        }
    }
    cout << count << "\n";
}

void DFS(int v) {
    visited[v] = true;
    for (int i : A[v]) {
        if (visited[i] == false) { // 연결 정점 중 방문하지 않았던 노드만 탐색함
            // 이 if 문이 없으면 메모리 초과임
            DFS(i);
        }
    }
}
```

## 2023 신기한소수
```c++
#include <iostream>
using namespace std;

void DFS(int number, int jarisu);
bool isPrime(int num);
static int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}

void DFS(int number, int jarisu) {
    if (jarisu == N) {
        if (isPrime(number)) {
            cout << number << "\n";
        }
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0) { // 짝수이면 더 이상 탐색할 필요가 없음
            continue;
        }
        if (isPrime(number * 10 + i)) { // 소수이면 재귀로 자리수를 늘려갑니다.
            DFS(number * 10 + i, jarisu + 1);
        }
    }
}

bool isPrime(int num) {
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}
```

## 13023 친구관계파악하기(ABCDE)
```c++
#include <iostream>
#include <queue>

using namespace std;

static vector<vector<int>> vec;
static vector<bool> visited;
void dfs(int num, int depth);
static bool isFive = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    vec.resize(a);
    visited = vector(a, false);
    for (int i = 0; i < b; i++) {
        int c, d;
        cin >> c >> d;
        vec[c].push_back(d);
        vec[d].push_back(c);
    }
    for(int i=0;i<a;i++){
        dfs(i, 0);
        if(isFive==true){
            break;
        }
    }
    if(isFive==true){
        cout << 1;
    }else{
        cout << 0;
    }
}

void dfs(int num, int depth) {
    depth++;
    visited[num]=true;
    if(depth==5){
        isFive = true;
        return;
    }
    for(int to : vec[num]){
        if(visited[to]==false){
            dfs(to, depth);
        }
    }
    // 함수에서 나올 때 아래와 같이 false처리를 안하면
    // 문제에서 제시되지 않은 테스트 케이스를 통과하지 못한다.
    // ex) 0-1 / 2-1-3-4-5
    // 이 경우에서 0,1을 방문하여 0,1이 true로 처리되면 2-1-3-4-5 탐색 시 1에서 끊겨 뎁스가 증가하지 않는다.
    visited[num]=false;
}
```