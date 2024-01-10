구간 합
===
기존의 배열을 전처리한 합 배열을 사용하여 시간 복잡도를 더 줄이기 위해 사용하는 특수한 목적의 알고리즘

아래는 구간 합의 사용 예시  
S는 합 배열, A는 기존 배열
```
S[5] = A[0] + A[1] + A[2] + A[3] + A[4] + A[5]
S[1] = A[0] + A[1]
S[5] - S[1] = A[2] + A[3] + A[4] + A[5]
```

# 11659 구간 합 구하기 1
```
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int suNo, quizNo;
	cin >> suNo >> quizNo;
	int S[100001] = {};

	for (int i = 1; i <= suNo; i++){
		int temp;
		cin >> temp;
		S[i] = S[i-1] + temp;	//구간합 구하기
	}

	for (int i = 0; i < quizNo; i++) {
		int start, end;
		cin >> start >> end;
		cout << S[end]-S[start-1] << "\n";
	}
}
```
## 원리
문제에서 합을 구해야 하는 횟수가 최대 100,000번인데 이 100,000번 모두 반복문을 사용하면
0.5안에 계산하지 못할 확률이 크다. 따라서 구간 합을 사용한다.

1. N개의 수를 입력받음과 동시에 합 배열을 생성한다.  
`S[i]=S[i-1]+A[i]`
2. 구간 i~j가 주어지면 구간 합을 구한다.  
`S[j]-S[i-1]`  
