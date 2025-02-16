#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define MAX 52

int N, M, K, len;
int result = INT_MAX;
int arr[MAX][MAX];
bool visited[7];
vector <int> R;
vector <int> C;
vector <int> S;

void turnArr(int s_r, int f_r, int s_c, int f_c) {
	int from = arr[s_r][s_c], to = 0;
	for (int i = s_c + 1; i <= f_c; i++) {
		to = arr[s_r][i];
		arr[s_r][i] = from;
		from = to;
	}
	for (int i = s_r + 1; i <= f_r; i++) {
		to = arr[i][f_c];
		arr[i][f_c] = from;
		from = to;
	}
	for (int i = f_c - 1; i >= s_c; i--) {
		to = arr[f_r][i];
		arr[f_r][i] = from;
		from = to;
	}
	for (int i = f_r - 1; i >= s_r; i--) {
		to = arr[i][s_c];
		arr[i][s_c] = from;
		from = to;
	}
}

void dfs(int cnt) {
	if (cnt == len) {
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += arr[i][j];
			}
			result = min(result, sum);
		}
		return;
	}

	int tmp[MAX][MAX];

	for (int i = 0; i < len; i++) {
		if (visited[i]) continue;
		else visited[i] = true;

		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				tmp[j][k] = arr[j][k];
			}
		}

		int start_r = (R[i] - S[i]), finish_r = (R[i] + S[i]), start_c = (C[i] - S[i]), finish_c = (C[i] + S[i]);

		while (start_r < finish_r && start_c < finish_c) {
			turnArr(start_r, finish_r, start_c, finish_c);
			start_r++, finish_r--, start_c++, finish_c--;
		}

		dfs(cnt + 1);

		visited[i] = false;

		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				arr[j][k] = tmp[j][k];
			}
		}
	}
}

int main() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	int r, c, s;

	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		R.push_back(r);
		C.push_back(c);
		S.push_back(s);
	}

	len = R.size();
	dfs(0);

	cout << result << "\n";

	return 0;
}
