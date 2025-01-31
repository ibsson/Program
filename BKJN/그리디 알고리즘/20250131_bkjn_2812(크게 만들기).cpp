#include <iostream>
#include <string>
using namespace std;

int N, K;
string num;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	cin >> num;

	int start = 0, tmp = 0;
	string result = "";
	int to_remove = K;

	for (int i = 0; i < N; i++) {
		while (!result.empty() && to_remove > 0 && result.back() < num[i]) {
			result.pop_back();
			to_remove--;
		}
		result.push_back(num[i]);
	}

	result = result.substr(0, N - K); //0부터 시작하는 N - K개의 문자를 result에 저장 (N = 10, K = 4, 9876543210일때 필요) 

	cout << result << "\n";

	return 0;
}
