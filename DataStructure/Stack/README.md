스택
===

# 1874 스택으로 수열 만들기

```c++
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    // 4 3 6 8 7 5 2 1
    vector<int> A(N, 0);
    // +,- 를 담는 벡터
    vector<char> resultV;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    stack<int> myStack;
    int num = 1; // 오름차순 수
    bool result = true;
    for (int i = 0; i < A.size(); i++) {
        int su = A[i]; // 현재 수열의 수
        if (su >= num) { //현재 수열 값 >= 오름차순 자연수 : 값이 같아 질 때까지 push()수행
            while (su >= num) { // push()
                myStack.push(num++);
                resultV.push_back('+');
            }
            myStack.pop();
            resultV.push_back('-');
        }
        else {  //현재 수열 값 < 오름차순 자연수: pop()을 수행하여 수열 원소를 꺼냅니다
            int n = myStack.top();
            myStack.pop();
            // 스택의 가장 위의 수가 만들어야 하는 수열의 수 보다 크다면 수열 출력 불가능
            if (n > su) {
                cout << "NO";
                result = false;
                break;
            } 
            else {
                resultV.push_back('-');
            }
        }
    }
    if (result) {
        for (int i = 0; i < resultV.size(); i++)
        {
            cout << resultV[i] << '\n';
        }
    }
}
```

## 결과값은 정답, 시간초과 풀이
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> inputVector(N, 0);
    stack<int> currentStack;
    vector<char> resultVector;
    bool result = true;

    for (int i = 0; i < N; i++) {
        cin >> inputVector[i];
    }

    int currentNumber = 1;
    for (int i = 0; i < N; i++) {
        int targetNumber = inputVector[i];
        if (currentNumber <= targetNumber) {
            while (currentNumber <= targetNumber) {
                currentStack.push(currentNumber);
                resultVector.push_back('+');
                currentNumber++;
            }
            currentStack.pop();
            resultVector.push_back('-');
        } else {
            if (currentStack.top() != targetNumber) {
                result = false;
                break;
            }
            currentStack.pop();
            resultVector.push_back('-');
        }
    }

    if (result) {
        for (int i = 0; i < resultVector.size(); i++) {
            cout << resultVector[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}
```
## 원리
![img.png](img/img.png)
![img.png](img/img1.png)