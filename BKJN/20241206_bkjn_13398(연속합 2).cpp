#include <iostream>
using namespace std;

int arr[100001];
int LeftSum[100001];
int RightSum[100001];
int n;
int result;

void Get_Max_Sum(int n) {

	LeftSum[0] = arr[0];
	result = LeftSum[0];

	for (int i = 1; i < n; i++) {
		LeftSum[i] = max(arr[i], LeftSum[i - 1] + arr[i]);
		if (result < LeftSum[i]) result = LeftSum[i];
	}

	if (n > 0) {
		RightSum[n - 1] = arr[n - 1];
		for (int i = (n - 2); i >= 0; i--) {
			RightSum[i] = max(arr[i], RightSum[i + 1] + arr[i]);
			if (result < RightSum[i]) result = RightSum[i];
		}
	}

	for (int i = 1; i < (n - 1); i++) {
		if (arr[i] < 0) {
			result = max(result, LeftSum[i - 1] + RightSum[i + 1]);
		}
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Get_Max_Sum(n);

	cout << result << endl;

	return 0;
}

/*
처음으로 골드티어 문제를 풀어냈다.
비록 온전히 내 힘으로 풀어낸 것은 아니다. 하지만 비슷한 생각을 해냈고, 시간초과가 날것이라고 생각해 검증해보지 않았다.
너무 바보같은 짓이었다. 앞으로는 괜찮은 것 같은 방법이 떠오르면 일단 한번 해보고 어떤결과가 나오는지 검증을 꼭 해봐야겠다.
*/
