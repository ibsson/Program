#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack <int> s;
stack <int> res;
vector <int> v;

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
	}
	
	s.push(v[N - 1]);
	res.push(-1);
	
	for (int i = (N - 2); i >= 0; i--) {
		while (!s.empty()) {
			if (v[i] >= s.top()) s.pop();
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

	return 0;
}

/*

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
*/
