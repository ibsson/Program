#include <iostream>
using namespace std;

int dp[50001] = { 0 };

int main(void) {

	int n = 0;

	cin >> n;

	dp[0] = 0; dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int min = 100000;
		for (int j = 1; (j * j) <= i; j++) {
			int tmp = i - (j * j);
			if (min > dp[tmp]) min = dp[tmp];
		}

		dp[i] = min + 1;
	}

	cout << dp[n] << endl;

	return 0;
}

/*
처음에는 그냥 브루트포스로 풀려고 했지만 계속 틀렸다고 해서 dp를 사용해서 풀었다.
하지만 풀리지 않아서 찾아서 풀었는데,
여전히 점화식을 찾는것은 어려운 것 같다.
dp[n]을 구하기 위해서 n 전까지의 배열에 각각의 수의 최솟값들을 넣어놓은 후 n에서 n보다 작은 제곱수들을 뺀 것 중 최솟값을 구하면 된다.
배열에 최솟값을 넣는것부터 시작한다는 생각을 못했지만 어느정도 점화식을 찾기 위한 감을 찾아가는 것 같다.
계속 풀어보면서 감을 찾아서 내꺼로 만들어야겠다.
*/
