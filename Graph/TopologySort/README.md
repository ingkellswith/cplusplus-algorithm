# 위상정렬
위상정렬은 진입차수 배열을 만들 때 다음으로 연결된 노드의 차수를 증가시키는 것이 핵심이다. 
# 2252 줄 세우기
```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector < vector <int> > A;
    vector <int>  indegree;
    A.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        A[S].push_back(E);
        indegree[E]++; // 진입차수 배열 데이터 저장하기
    }
    queue<int> queue;  // 위상 정렬 수행
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        cout << now << " ";
        for (int next : A[now]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                queue.push(next);
            }
        }
    }
}
```

# 1516 게임 개발하기
가중치가 노드에 있음
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector < vector <int> > A;
    vector <int>  indegree;     // 진입차수배열
    vector <int>  selfBuild;
    A.resize(N + 1);
    indegree.resize(N + 1);
    selfBuild.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> selfBuild[i]; // 해당 건물을 짓기 위한 시간
        while (true) { // 인접리스트 데이터 저장
            int preTemp;
            cin >> preTemp;
            if(preTemp == -1)
                break;
            A[preTemp].push_back(i);
            indegree[i]++; // 진입차수 데이터 저장
        }
    }

    queue<int> queue;  // 위상 정렬 수행
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }
    vector <int>  result;
    result.resize(N + 1,0);

    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        for (int next : A[now]) {
            indegree[next]--;
            result[next] = max(result[next], result[now] + selfBuild[now]);
            if (indegree[next] == 0) {
                queue.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
       cout << result[i] + selfBuild[i] << "\n";
    }
}
```

# 1948 임계 경로 구하기
가중치가 엣지에 있음
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector < vector <pair<int, int>> > A;
    vector < vector <pair<int, int>> > reverseA;
    vector <int> indegree;     // 진입차수배열
    A.resize(N + 1);
    reverseA.resize(N + 1);
    indegree.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int S, E, V;
        cin >> S >> E >> V;
        A[S].push_back(make_pair(E, V));
        reverseA[E].push_back(make_pair(S, V));  // 역방향 간선 정보 저장
        indegree[E]++;	 // 진입 차수 배열 초기화
    }

    int startDosi, endDosi;
    cin >> startDosi >> endDosi;

    queue<int> mqueue;  	// 위상 정렬 수행
    mqueue.push(startDosi);
    vector <int> result;
    result.resize(N + 1);

    while (!mqueue.empty()) {
        int now = mqueue.front();
        mqueue.pop();
        for (pair<int, int> next : A[now]) {
            indegree[next.first]--;
            // 이 부분이 바로 윗 문제인 1516번과 다름
            result[next.first] = max(result[next.first], result[now] + next.second);
            if (indegree[next.first] == 0) {
                mqueue.push(next.first);
            }
        }
    }
    // 위상 정렬 reverse
    int resultCount = 0;
    vector <bool> visited;
    visited.resize(N + 1);
    queue<int> rqueue;
    rqueue.push(endDosi);
    visited[endDosi] = true;
    while (!rqueue.empty()) {
        int now = rqueue.front();
        rqueue.pop();
        for (pair<int, int> next : reverseA[now]) {
            if (result[next.first] + next.second == result[now]) { 	// 1분도 쉬지 않는 도로 체크
                resultCount++;
                if (visited[next.first] == false) { 	// 중복 카운트 방지를 위해 기 방문 노드 제외
                    visited[next.first] = true;
                    rqueue.push(next.first);
                }
            }
        }
    }
    cout << result[endDosi] << "\n";
    cout << resultCount << "\n";
}
```