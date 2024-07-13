# 다익스트라
한 번 방문한 노드의 최단 경로는 더 이상 변경되지 않으며, 이를 바탕으로 다른 노드들의 최단 경로를 점진적으로 갱신한다.

# 1753 최단 경로 구하기
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int V, E, K;
static vector<int> mdistance;
static vector<bool> visited;
static vector < vector <edge> > mlist;
// 최소 힙
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    mdistance.resize(V + 1);
    std::fill(mdistance.begin(), mdistance.end(), INT_MAX);

    visited.resize(V + 1);
    std::fill(visited.begin(), visited.end(), false);
    mlist.resize(V + 1);

    for (int i = 0; i < E; i++) { // 가중치가 있는 인접 리스트 초기화
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }

    q.push(make_pair(0, K));
    mdistance[K] = 0;
    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;
        if (visited[c_v]) continue; // 기 방문 노드는 다시 큐에 넣지 않습니다.
        visited[c_v] = true;
        for (int i = 0; i < mlist[c_v].size(); i++) {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;
            if (mdistance[next] > mdistance[c_v] + value) { // 최소 거리로 업데이트
                mdistance[next] = value + mdistance[c_v];
                q.push(make_pair(mdistance[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++) { // 거리 배열 출력
        if (visited[i])
            cout << mdistance[i] << "\n";
        else
            cout << "INF" << "\n";
    }
}
```

# 1916 최소 비용 구하기
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int N, M;
static vector<int> dist;
static vector<bool> visited;
static vector < vector <edge> > mlist;
int dijkstra(int start, int end);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dist.resize(N + 1);
    std::fill(dist.begin(), dist.end(), INT_MAX);

    visited.resize(N + 1);
    std::fill(visited.begin(), visited.end(), false);
    mlist.resize(N + 1);

    for (int i = 0; i < M; i++) {	 // 가중치가 있는 인접 리스트 초기화
        int start, end, weight;
        cin >> start >> end >> weight;
        mlist[start].push_back(make_pair(end, weight));
    }

    int startIndex, endIndex;
    cin >> startIndex >> endIndex;

    int result = dijkstra(startIndex, endIndex);
    cout << result << "\n";
}

// mlist와 pq의 자료구조의 순서 주의
int dijkstra(int start, int end) {   	// 다익스트라 알고리즘
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push(make_pair(0, start));	// 비용 기준 정렬을 위해 데이터 순서를 비용, 노드로 설정
    dist[start] = 0;
    while (!pq.empty()) {
        edge nowNode = pq.top();
        pq.pop();
        int now = nowNode.second;
        if (!visited[now]) {
            visited[now] = true;
            for (edge n : mlist[now]) { // 선택노드 + 비용 < 타켓노드인 경우 값을 갱신하는 부분
                if (dist[n.first] > dist[now] + n.second) {
                    dist[n.first] = dist[now] + n.second;
                    pq.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }
    return dist[end];
}
```

# 1854 K번째 최단 경로 찾기
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> Node;
static int N, M, K;
static int W[1001][1001];
static priority_queue<int> distQueue[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) { // 가중치가 있는 인접 리스트 초기화
        int a, b, c;
        cin >> a >> b >> c;
        W[a][b] = c;
    }
    // 최소 힙
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, 1));
    distQueue[1].push(0);

    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        for (int adjNode = 1; adjNode <= N; adjNode++) {
            // 연결된 모든 노드에 대하여 검색하기 
            if (W[u.second][adjNode] != 0) {
                // 저장된 경로가 K개가 안될 경우 그냥 추가한다.
                if (distQueue[adjNode].size() < K) {
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
                // 저장된 경로가 K개이고, 현재 가장 큰 값보다 작을때만 추가한다.
                else if (distQueue[adjNode].top() > u.first + W[u.second][adjNode]) {
                    distQueue[adjNode].pop(); // 기존 큐에서 Max값 삭제먼저 해주어야함
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) { // K번째 경로 출력
        if (distQueue[i].size() == K) {
           cout << distQueue[i].top() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}
```