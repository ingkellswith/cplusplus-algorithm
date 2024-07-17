# 11725 트리의 부모 찾기
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

static int N;
static vector<int> answer;
static vector<bool> visited;
static vector < vector <int> > tree;
void DFS(int number);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    visited.resize(N + 1);
    tree.resize(N + 1);
    answer.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    DFS(1);	// 루트 노드에서 DFS 실행
    for (int i = 2; i <= N; i++) {
        cout << answer[i] << "\n";
    }
}

void DFS(int number) {
    visited[number] = true;
    for (int i : tree[number]) {
        if (!visited[i]) {
            answer[i] = number;	// 부모노드를 정답 배열에 저장하기
            DFS(i);
        }
    }
}
```

# 1068 리프 노드의 개수 구하기
```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N;
static vector < vector <int> > tree;
static int answer = 0;
static int deleteNode = 0;
static vector<bool> visited;
void DFS(int number);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    visited.resize(N);
    tree.resize(N);
    int root = 0;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if(p != -1){
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else {
            root = i;
        }
    }
    
    cin >> deleteNode;
    if (deleteNode == root) {
        cout << 0 << "\n";
    }
    else {
        DFS(root);
        cout << answer << "\n";
    }
}

void DFS(int number) {
    visited[number] = true;
    int cNode = 0;
    for (int i : tree[number]) {
        if (visited[i] == false && i != deleteNode ) {
            cNode++;
            DFS(i);
        }
    }
    // 리프 노드에서는 반복문이 수행되지 않으므로 answer에 1을 더해준다.
    if (cNode == 0) {
        answer++;
    }
}
```
