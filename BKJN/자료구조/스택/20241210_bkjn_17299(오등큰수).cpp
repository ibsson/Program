#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000001
using namespace std;

int cnt[MAX];
vector <int> v;
stack <int> s;
stack <int> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		cnt[tmp]++;
	}

	s.push(v[N - 1]);
	res.push(-1);

	for (int i = (N - 2); i >= 0; i--) {
		while (!s.empty()) {
			if (cnt[v[i]] >= cnt[s.top()]) s.pop();
			else break;
		}

		if (s.empty()) res.push(-1);
		else res.push(s.top());

		s.push(v[i]);
	}

	while (!res.empty()) {
		cout << res.top() << ' ';
		res.pop();
	}
	cout << '\n';

	return 0;
}

/*
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
*/
