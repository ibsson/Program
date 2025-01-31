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

/*
string 객체를 스택처럼 사용했다.
되게 창의적으로 풀리는 문제였던 것 같다.
난이도가 올라갈수록 자료구조를 사용하는것이 필수적이라는 사실을 깨닫게 되었다. 
잘 분석해서 이런 유형으로 나오는 문제를 풀 수 있도록 해야겠고, 코드의 성능을 높이기 위해 자료구조를 적절하게 잘 사용하는 연습을 해야겠다.
*/
