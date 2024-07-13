# 1717 집합의 표현
```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static  vector<int> parent;

void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 0; i <= N; i++) { 	// 대표 노드를 자기 자신으로 초기화 하기
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int question, a, b;
        cin >> question >> a >> b;
        if (question == 0) { 	// 집합 합치기
            unionfunc(a, b);
        }
        else {	 // 같은 집합의 원소인지 확인하기
            if (checkSame(a, b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}
void unionfunc(int a, int b) { 	// union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) {	 // find 연산 : 대표 노드를 찾아서 리턴
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);	 // 대표 노드에 도달하면 재귀 함수를 빠져나오면서 거치는 모든 노드값을 대표 노드값으로 변경
        // a,b,c를 생각해보면 a,b의 parent는 c가 됨
}
bool checkSame(int a, int b) { // 두 원소가 같은 집합인지 확인
    a = find(a);
    b = find(b);
    if (a == b) {
        return true;
    }
    return false;
}
```

# 1976 여행계획짜기
```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static  vector<int> parent;

void unionfunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int dosi[201][201];
    for (int i = 1; i <= N; i++) { 	// 도시 연결 데이터 저장
        for (int j = 1; j <= N; j++) {
            cin >> dosi[i][j];
        }
    }
    int route[1001];
    for (int i = 1; i <= M; i++) { 	//여행 도시 정보 저장
        cin >> route[i];
    }
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) { 	// 대표 노드를 자기 자신으로 초기화
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) { 	// 인접행렬 탐색에서 도시가 연결되어 있으면 유니온 실행
        for (int j = 1; j <= N; j++) {
            if (dosi[i][j] == 1) unionfunc(i, j);
        }
    }

    // 여행 계획 도시들이 하나의 대표 도시로 연결되어 있는지 확인
    int index = find(route[1]);
    bool connect = true;
    for (int i = 2; i <= M; i++) {
        if (index != find(route[i])) {
            cout << "NO" << "\n";
            connect = false;
            break;
        }
    }
    if (connect) cout << "YES" << "\n";
}
void unionfunc(int a, int b) {	 // union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { 	// find 연산 : 대표 노드를 리턴
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); 	// 재귀함수의 형태로 구현
}
```

# 1043 거짓말쟁이가 되긴 싫어
```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static  vector<int> parent;
static  vector<int> trueP;
static vector < vector <int> > party;
static int result;

void unionfunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T;
    cin >> N >> M >> T;
    trueP.resize(T);
    for (int i = 0; i < T; i++) { // 진실을 아는 사람 저장
        cin >> trueP[i];
    }
    
    party.resize(M);

    for (int i = 0; i < M; i++) { // 파티 데이터 저장
        int party_size;
        cin >> party_size;
        for (int j = 0; j < party_size; j++) {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) { // 대표 노드를 자기 자신으로 초기화 하기
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) { // 각 파티에 참여한 사람들을 하나의 그룹으로 만들기 -> union 연산
        int firstPeople = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            unionfunc(firstPeople, party[i][j]);
        }
    }
    for (int i = 0; i < M; i++) { // 각 파티에서 진실을 아는 사람과 같은 그룹에 있다면 과장 할 수 없음
        bool isPossible = true;
        int cur = party[i][0];
        for (int j = 0; j < T; j++) {
            if (find(cur) == find(trueP[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible)
            result++;
    }
    cout << result;
}
void unionfunc(int a, int b) { // union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}
int find(int a) { // find 연산
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]); // 재귀함수의 형태로 구현
}
```