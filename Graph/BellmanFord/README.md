# 11657 타임머신으로 빨리 가기
```c++
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;


typedef tuple<int, int, int> edge;
static int N, M;
static vector<long> mdistance;
static vector <edge> edges;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    mdistance.resize(N + 1);
    std::fill(mdistance.begin(), mdistance.end(), LONG_MAX); // 최단거리 배열 초기화

    for (int i = 0; i < M; i++) { // 간선 리스트에 데이터 저장하기
        int start, end, time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start, end, time));
    }

    // 벨만포드 알고리즘 수행
    // 다익스트라와 초기화된 배열의 형태가 같음
    mdistance[1] = 0;
    // 두 노드의 최단 거리를 구성할 수 있는 최대 간선 수가 N-1개이기 때문에 N-1만큼 반복. N은 노드의 개수.
    for (int i = 1; i < N; i++) {  // N보다 하나 적은 수만큼 반복
        for (int j = 0; j < M; j++) {
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);
            // 더 작은 최단거리 가 있는 경우 갱신
            if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
                mdistance[end] = mdistance[start] + time;
            }
        }
    }
    bool mCycle = false;
    // 다시 한 번 반복문을 실행했을 때 업데이트되는 노드가 있다면 음수 사이클이 존재한다는 뜻
    for (int i = 0; i < M; i++) { // 음수 cycle 확인
        edge medge = edges[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);
        if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
            mCycle = true;
        }
    }
    if (!mCycle) { // 음의 cycle이 없는 경우
        for (int i = 2; i <= N; i++) {
            if (mdistance[i] == LONG_MAX)
                cout << -1 << "\n";
            else
                cout << mdistance[i] << "\n";
        }
    }
    else { // 음의 cycle이 있는 경우
        cout << -1 << "\n";
    }
}
```

# 1219 세일즈맨의 고민
```c++
#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;


typedef tuple<int, int, int> edge;
static int N, M, sCity, eCity;
static vector<long> mdistance, cityMoney;
static vector <edge> edges;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> sCity >> eCity >> M;

    mdistance.resize(N);
    cityMoney.resize(N);
    std::fill(mdistance.begin(), mdistance.end(), LONG_MIN); // 최단거리 배열 초기화

    for (int i = 0; i < M; i++) { // 에지 리스트에 데이터 저장하기
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end, price));
    }

    for (int i = 0; i < N; i++) {
        cin >> cityMoney[i];
    }

    
    mdistance[sCity] = cityMoney[sCity]; // 변형된 벨만포드 알고리즘 수행
    for (int i = 0; i <= N + 100; i++) { // 양수싸이클이 전파되도록 충분히 큰 수로 반복하기
        for (int j = 0; j < M; j++) {
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int price = get<2>(edges[j]);
            if (mdistance[start] == LONG_MIN) continue; // 시작노드가 미방문 노드이면 continue
            // 시작 노드가 양수사이클에 연결된 노드라면 종료 노드도 연결 노드로 갱신
            else if (mdistance[start] == LONG_MAX)
                mdistance[end] = LONG_MAX;
            // 더 많은 돈을 벌수 있는 새로운 경로가 발견된 경우 새로운 경로 값으로 갱신
            else if (mdistance[end] < mdistance[start] + cityMoney[end] - price) {
                mdistance[end] = mdistance[start] + cityMoney[end] - price;
                // N-1 반복 이후 갱신되는 종료 노드는 양수사이클 연결 노드로 변경
                if (i >= N - 1)
                    mdistance[end] = LONG_MAX;
            }
        }
    }
    if (mdistance[eCity] == LONG_MIN) cout << "gg"<< "\n"; // 도착 불가능
    else if (mdistance[eCity] == LONG_MAX) cout << "Gee" << "\n"; // 양수사이클 연결
    else cout << mdistance[eCity] << "\n"; //그 이외의 경우
}
```