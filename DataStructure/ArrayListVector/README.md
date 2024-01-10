배열과 리스트 그리고 벡터
===
# 11720 숫자의 합 구하기
```
#include <iostream>
using namespace std;
int main()
{
	int N = 0;
	string numbers;
	cin >> N;
	cin >> numbers;

	int sum = 0;
	for (int i = 0; i < numbers.length(); i++){
		sum += numbers[i] - '0';
	}
	cout << sum << "\n";
}
```
## 원리
N의 범위가 int, long을 초과하므로 숫자를 char으로 취급하고, 이 char에서 '0'을 뺄셈하여 계산  

# 1546 평균 구하기
```
#include <iostream>
using namespace std;
int main()
{
	int N = 0;
	int A[1000];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	long sum = 0;
	long max = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > max) {
			max = A[i];
		}
		sum = sum + A[i];
	}
	// 한 과목과 관련된 수식을 총합한 후 관련된 수식으로 변환해 로직이 간단해짐
	double result = sum * 100.0 / max / N;	
	cout << result << "\n";
}
```
## 원리
잘 풀기 위해서 문제 풀이 중에 손으로 계산해보는 과정이 반드시 필요하다. 
계산해보면 결국 (총합 * 100 / 최고 점수 / 과목의 수)이 답이다.
