#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

vector <int> v[MAX];
bool visited[MAX];

int res = 0;

int DFS(int cur) {
	visited[cur] = true;

	if (cur != 1 && v[cur].size() == 1) {
		res++;
		return 1;
	}

	int sum = 0;

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];

		if (!visited[next]) {
			sum += DFS(next);
		}
	}

	if (cur == 1) return 0;

	res += sum;
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < (N - 1); i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);
	
	if (res % 2 == 0) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}
