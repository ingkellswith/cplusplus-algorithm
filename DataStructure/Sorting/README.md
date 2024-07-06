# 2750 수 정렬하기 - 버블 정렬
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
  
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }
}
```

# 1377 버블 정렬 프로그램1 - 버블 정렬

코드 자체는 간단하지만 아이디어를 모르면 풀 수 없는 문제, 테스트 케이스 여러 개를 직접 계산해봐야 규칙 도출 가능
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end()); //A배열 정렬 O(nlogn)시간 복잡도

    int Max = 0;
    for (int i = 0; i < N; i++) {
        if (Max < A[i].second - i) //정렬 전 index - 정렬 후 index 계산 값의 최대 값을 찾아 저장
            Max = A[i].second - i;
    }
    cout << Max + 1;
}
```

# 1427 소트인사이드 - 선택 정렬
```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> A(str.size(), 0);
    for (int i = 0; i < str.size(); i++) {
        A[i] = stoi(str.substr(i, 1));
    }

    for (int i = 0; i < str.length(); i++) {
        int Max = i;
        for (int j = i + 1; j < str.length(); j++) {
            if (A[j] > A[Max])  //내림차순이므로 최대 값을 찾음
                Max = j;
        }
        if (A[i] < A[Max]) {
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
   
}
```

STL 사용한 버전
```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    // vector<int> A(str.size()); 도 가능
    vector<int> A(str.size(),0);
    for (int i = 0; i < str.size(); i++) {
        A[i] = stoi(str.substr(i, 1));
    }

    // 내림차순 정렬
    sort(A.begin(), A.end(), greater<int>());

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }

    return 0;
}
```

# 11399 ATM - 삽입 정렬
역시 STL 사용 가능
```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<int> S(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < N; i++) { //삽입 정렬
        int insert_point = i;
        int insert_value = A[i];
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]){
                insert_point = j + 1;
                break;
            }
            if (j == 0) {
                insert_point = 0;
            }
        }
        for (int j = i; j > insert_point; j--) {
            A[j] = A[j - 1];
        }
        A[insert_point] = insert_value;
    }

    S[0] = A[0]; //합배열 만들기 
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    int sum = 0; //합배열 총합 구하기
    for (int i = 0; i < N; i++) {
        sum = sum + S[i];
    }

    cout << sum;

}
```