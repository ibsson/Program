#include <iostream>
#include <vector>
using namespace std;

int K;
vector <int> v;
vector <int> num[11];

void dfs(int idx, int depth, int start, int end) {
	num[depth].push_back(v[idx]);

	if (depth == K) return;

	dfs((start + idx) / 2, depth + 1, start, idx - 1);
	dfs((idx + (end + 1)) / 2, depth + 1, idx, end);
}

int main(void) {

	cin >> K;

	int cnt = 1;

	for (int i = 1; i <= K; i++) {
		cnt *= 2;
	}

	for (int i = 0; i < (cnt - 1); i++) {
		int tmp = 0;

		cin >> tmp;

		v.push_back(tmp);
	}

	int rootIndex = v.size() / 2;

	dfs(rootIndex, 1, 0, v.size() - 1);

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < num[i].size(); j++) {
			cout << num[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}

/*
재귀를 이용한 분할정복 기법으로 구현했고, 재귀의 깊이는 곧 트리의 깊이가 된다는 점을 이용해서 문제를 풀었다.
조금 어려웠지만 천천히 생각하면서 코드를 만들다 보니 풀 수 있었다.
*/
