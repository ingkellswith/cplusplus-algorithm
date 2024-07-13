## 1260 DFS와 BFS
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>  // Include the stack library

using namespace std;

static vector < vector <int> > A;
static vector<bool> visited;
void DFS(int node);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Start;
    cin >> N >> M >> Start;
    A.resize(N+1);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    // Sort adjacency lists to visit nodes in numerical order
    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    visited = vector<bool>(N+1, false); 
    DFS(Start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false); // Reset visited array
    BFS(Start);
    cout << "\n";
}

// ver1 재귀
void DFS(int node) {
    cout << node << " ";
    visited[node] = true;
    for (int i : A[node]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

// ver2 스택
void DFS(int node) {
    stack<int> mystack;
    mystack.push(node);

    while (!mystack.empty()) {
        int now_node = mystack.top();
        mystack.pop();
        if (!visited[now_node]) {
            cout << now_node << " ";
            visited[now_node] = true;
            for (auto it = A[now_node].rbegin(); it != A[now_node].rend(); ++it) {
                mystack.push(*it);
            }
        }
    }
}

void BFS(int node) { 
    queue<int> myqueue;
    myqueue.push(node);

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        if (!visited[now_node]) {
            cout << now_node << " ";
            visited[now_node] = true;
            for (int i : A[now_node]) {
                myqueue.push(i);
            }
        }
    }
}

// ver2 for 안의 if
void BFS(int node) { 
    queue<int> myqueue;
    myqueue.push(node);
    visited[node]=true;
    cout << node << " ";
    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        for (int i : A[now_node]) {
          if (!visited[i]) {
            cout << i << " ";
            visited[i] = true;
            myqueue.push(i);
          }
        }
    }
}
```

## 2178 미로 탐색하기
```c++
#include <iostream>
#include <queue>
using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int A[101][101];
static bool visited[101][101] = { false };
static int N, M;
void BFS(int i, int j);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    BFS(0,0);
    cout << A[N-1][M-1] << "\n";
}

void BFS(int i, int j) {
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(i, j));
    // visited 매트릭스에서 0,0은 항상 1이므로
    visited[i][j] = true;
    while (!myqueue.empty()) {
        int now[2];
        now[0] = myqueue.front().first;
        now[1] = myqueue.front().second;
        myqueue.pop();
        for (int k = 0; k < 4; k++) {
            int x = now[0] + dx[k];
            int y = now[1] + dy[k];
            if (x >= 0 && y >= 0 && x < N && y < M) {
                if (A[x][y] != 0 && !visited[x][y]) {
                    visited[x][y] = true;
                    A[x][y] = A[now[0]][now[1]] + 1; // depth update
                    myqueue.push(make_pair(x, y));
                }
            }
        }
    }
}
```

## 1167 트리의 지름

아이디어 : 임의의 노드에서 가장 긴 경로로 연결된 노드는 트리의 지름에 해당하는 두 노드 중 하나다.
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
static vector < vector <edge> > A;
static vector<bool> visited;
static vector<int> m_distance;
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while (true)
        {
            int E, V;
            cin >> E;
            if (E == -1)break;
            cin >> V;
            A[S].push_back(edge(E, V));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N+1, false);
    BFS(1);
    int Max = 1;
    for (int i = 2; i <= N; i++) {
        if (m_distance[Max] < m_distance[i])
            Max = i;
    }
    fill(m_distance.begin(), m_distance.end(), 0); // 거리 배열 초기화
    fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
    BFS(Max);
    sort(m_distance.begin(), m_distance.end());
    cout << m_distance[N] << "\n";
}


void BFS(int index) {
    queue<int> myqueue;
    myqueue.push(index);
    // 2178도 동일 원리, 일반 BFS와 다른 visited 시점 유의
    visited[index] = true;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        for (edge i : A[now_node]) {
            if (!visited[i.first]) {
                visited[i.first] = true;
                myqueue.push(i.first);
                m_distance[i.first] = m_distance[now_node] + i.second;
            }
        }
    }
}
```