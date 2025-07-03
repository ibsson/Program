#include <iostream>
#include <stack>
using namespace std;

int a[1000001];
int NGE[1000001];
int N = 0;
stack <int> s;

void Get_Result() {

	for (int i = 0; i < N; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			NGE[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		NGE[s.top()] = -1;
		s.pop();
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	Get_Result();

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << " ";
	}
	cout << "\n";

	return 0;
}

/*
STL stack을 사용해서 쉽게 풀었다.
*/
