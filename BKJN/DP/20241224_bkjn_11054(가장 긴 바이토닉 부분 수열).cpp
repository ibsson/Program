#include <iostream>
#include <vector>
#define MAX 1002
using namespace std;

vector <int> A;
int dp1[MAX];
int dp2[MAX];
int res[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	for (int i = (N - 1); i >= 0; i--) {
		dp2[i] = 1;
		for (int j = (N - 1); j > i; j--) {
			if (A[i] > A[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		res[i] = dp1[i] + dp2[i] - 1;
		ans = max(ans, res[i]);
	}

	cout << ans << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

int num[1001];
int dp_1[1001];
int dp_2[1001];

int main(void) {

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < N; i++) {
		dp_1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) {
				dp_1[i] = max(dp_1[i], dp_1[j] + 1);
			}
		}
	}

	for (int i = (N - 1); i >= 0; i--) {
		dp_2[i] = 1;
		for (int j = (N - 1); j > i; j--) {
			if (num[i] > num[j]) {
				dp_2[i] = max(dp_2[i], dp_2[j] + 1);
			}
		}
	}

	int result = -1;

	for (int i = 0; i < N; i++) {
		result = max(result, (dp_1[i] + dp_2[i] - 1));
	}

	cout << result << "\n";

	return 0;
}

/*
이 문제는 도저히 풀리지 않아서 다른 사람의 코드를 참고했다.
최장 증가 부분 수열 (LIS)알고리즘을 활용했다.
앞에서부터 비교한 최장 증가 길이와 뒤에서부터 비교한 최장 증가 길이를 더했을때 가장 큰 지점이 정답이다.
조금 어려웠던 문제였다. 이런 생각의 도약을 해낼 수 있도록 더 노력해야겠다.
*/
*/
