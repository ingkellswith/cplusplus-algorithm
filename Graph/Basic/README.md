# 18352 특정 거리의 도시 찾기
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);

static vector < vector <int> > A;
static vector<int> answer;
static vector<int> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M, K, X;
    cin >> N >> M >> K >> X;
    A.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        A[S].push_back(E);
    }
    visited.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        visited[i] = -1;
    }
    BFS(X);
    for (int i = 0; i <= N; i++) {
        if (visited[i] == K) {
            answer.push_back(i);
        }
    }
    if (answer.empty()) {
        cout << -1 << "\n";
    }
    else {
        sort(answer.begin(), answer.end());
        for (int temp : answer) {
            cout << temp << "\n";
        }
    }
}

void BFS(int node) {
    queue<int> queue;
    queue.push(node);
    visited[node]++;
    while (!queue.empty()) {
        int now_node = queue.front();
        queue.pop();
        for (int i : A[now_node]) {
            if (visited[i] == -1) {
                visited[i] = visited[now_node] + 1;
                queue.push(i);
            }
        }
    }
}
```

# 1325 효율적인 해킹
BFS 풀이
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS(int node);

static vector < vector <int> > A;
static vector<int> answer;
static vector<bool> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M;
    cin >> N >> M;
    A.resize(N + 1);
    answer.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        A[S].push_back(E);
    }
    visited.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }
    int maxVal = 0;
    for (int i = 1; i <= N; i++) {
        maxVal = max(maxVal, answer[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (answer[i] == maxVal) //answer배열에서 maxVal와 같은 값을 가진 index를 정답으로 출력
           cout << i << " ";
    }
}

void BFS(int index) {
    queue<int> queue;
    queue.push(index);
    visited[index] = true;
    while (!queue.empty()) {
        int now_node = queue.front();
        queue.pop();
        for (int i : A[now_node]) {
            if (visited[i] == false) {
                visited[i] = true;
                answer[i]++; //신규 정점인덱스의 정답 배열 값을 증가 시키기  
                queue.push(i);
            }
        }
    }
}
```

DFS 풀이
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int node);

static vector < vector <int> > A;
static vector<int> answer;
static vector<bool> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, M;
    cin >> N >> M;
    A.resize(N + 1);
    answer.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        A[S].push_back(E);
    }
    visited.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        DFS(i);
    }
    int maxVal = 0;
    for (int i = 1; i <= N; i++) {
        maxVal = max(maxVal, answer[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (answer[i] == maxVal) //answer배열에서 maxVal와 같은 값을 가진 index를 정답으로 출력
            cout << i << " ";
    }
}

void DFS(int node) {
    visited[node] = true;
    answer[node]++;
    for (int i : A[node]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}
```

# 1707 이분 그래프 판별하기
사이클이 아닌 트리는 이분 그래프이다.
아이디어 - DFS를 실행하면서 방문 노드에 이전 노드와 다른 모집합 설정.
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void DFS(int node);

static vector < vector <int> > A;
static vector<int> check;
static vector<bool> visited;
static bool IsEven;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int t = 0; t < N; t++) {
        int V, E;
        cin >> V >> E;
        A.resize(V + 1);
        visited.resize(V + 1);
        check.resize(V + 1);
        // 사이클인지 아닌지 판단하는 변수
        IsEven = true;
        for (int i = 0; i < E; i++) {
            int S, E;
            cin >> S >> E;
            A[S].push_back(E);
            A[E].push_back(S);
        }
        // 주어진 그래프가 하나로 연결되어 있다는 보장이 없으므로 모든 정점에서 수행
        for (int i = 1; i <= V; i++) {
            if (IsEven)
                DFS(i);
            else
                break;
        }
        if (IsEven)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        for (int i = 0; i <= V; i++) {
            A[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
    }
}


void DFS(int node) {
    visited[node] = true;
    for (int i : A[node]) {
        if (!visited[i]) {
            check[i] = (check[node] + 1) % 2; 	// 인접한 정점은 같은 집합이 아니므로 이전 정점과 다른 집합으로 처리
            DFS(i);
        }
        else if (check[node] == check[i]) { 	// 이미 방문한 정점이 현재 내 정점과 같은 집합이면 이분 그래프가 아님
            IsEven = false;
        }
    }
}
```

# 2251 물의 양 구하기
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void BFS();
static int Sender[] = {0, 0, 1, 1, 2, 2};
static int Receiver[] = {1, 2, 0, 2, 0, 1};
static bool visited[201][201];  //A B의 무게만 있으면 C의 무게가 고정되므로 2개로만 체크 가능
static bool answer[201];
static int now[3]; // A B C 물의 양을 저장하는 배열

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> now[0] >> now[1] >> now[2]; 
    BFS();
    
    for (int i = 0; i < 201; i++) {
        if (answer[i]) cout << i << " ";
    }
}

void BFS() {
    queue<pair<int,int>> queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    answer[now[2]] = true;
    while (!queue.empty()) {
        pair <int, int> p = queue.front();
        queue.pop();
        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B; // C는 전체 물의 양에서 A와 B를 빼준 것
        for (int k = 0; k < 6; k++) { // A->B, A->C, B->A, B->C, C->A, C->B 6개의 케이스로 이동
            int next[] = { A, B, C };
            next[Receiver[k]] += next[Sender[k]];
            next[Sender[k]] = 0;
            if (next[Receiver[k]] > now[Receiver[k]]) { // 대상 물통의 용량보다 물이 많아 넘칠 때
                // 초과하는 만큼 다시 이전 물통에 넣어줌
                next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
                next[Receiver[k]] = now[Receiver[k]]; // 대상 물통은 최대로 채워줌
            }
            if (!visited[next[0]][next[1]]) { // A와 B의 물의 양을 통하여 방문 배열 체크
                visited[next[0]][next[1]] = true;
                queue.push(make_pair(next[0], next[1]));
                if (next[0] == 0) {  // A의 물의 양이 0일때 C의 물의 무게를 정답 변수에 저장
                    answer[next[2]] = true;
                }
            }
        }
    }
}
```