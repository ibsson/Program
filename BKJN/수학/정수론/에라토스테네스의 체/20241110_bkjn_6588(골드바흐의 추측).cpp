#include <iostream>
#include <cmath>
using namespace std;

int prime_num[1000001] = { 0 };

void eratos(int);
void Print_Result(int);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n = 0;

	eratos(1000001);

	while (1) {
		cin >> n;

		if (n == 0) break;

		Print_Result(n);
	}

	return 0;
}

void eratos(int N) {

	for (int i = 2; i <= sqrt(N); i++) {
		for (int k = 2; k * i <= N; k++) {
			prime_num[k * i] = 1;
		}
	}
}

void Print_Result(int N) {

	int left = 0, right = 0;

	left = 3;
	right = N - 3;

	while (left <= right){
		if (!prime_num[left] && !prime_num[right])
			if ((left + right) == N)
				break;
		left += 2;
		right -= 2;
	}

	if (left > right)  cout << "Goldbach's conjecture is wrong.";
	else cout << N << " = " << left << " + " << right << '\n';
}

/*
에라토스테네스의 체를 사용해서 풀었는데 계속 시간초과가 나서 이런저런 방법을 다 써봤다.
소수들을 잘 살펴보니 가장 가까운 소수들의 간격이 짝수라는것을 발견했다. 이것을 이용해서
N에서 3을 뺀 수에서 시작해 양쪽에서 2씩 줄어들고 늘어난 수를 더하면 N이 나온다는 사실을 알게되었고, 이렇게 계속 하다가 두 수 모두 소수라면 그게 정답이 된다고 생각했다.
그렇게 구현해냈다. 오래 걸린 문제였지만 규칙을 찾아내고 풀어내서 기분이 좋았다.
*/
