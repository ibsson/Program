#include <iostream>
#include <stack>
using namespace std;

int N;
int A[1000001];
int F[1000001];
int NGF[1000001];
stack <int> s;

void Get_Result() {

	for (int i = 0; i < N; i++) {
		F[A[i]]++;
	}

	for (int i = 0; i < N; i++) {
		while (!s.empty() && F[A[s.top()]] < F[A[i]]) {
			NGF[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		NGF[s.top()] = -1;
		s.pop();
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	Get_Result();

	for (int i = 0; i < N; i++) {
		cout << NGF[i] << " ";
	}
	cout << "\n";	

	return 0;
}
