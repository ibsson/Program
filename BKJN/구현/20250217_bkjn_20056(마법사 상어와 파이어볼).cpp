#include <iostream>
#include <vector>
using namespace std;

#define MAX 52

int N, M, K, result;
struct Fireball {
	int R;
	int C;
	int W;
	int S;
	int D;
};

int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector <Fireball> grid[MAX][MAX];
vector <Fireball> v;

void order() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].S; j++) {
			v[i].R += dr[v[i].D], v[i].C += dc[v[i].D];
			if (v[i].R == 0) v[i].R = N;
			if (v[i].R == (N + 1)) v[i].R = 1;
			if (v[i].C == 0) v[i].C = N;
			if (v[i].C == (N + 1)) v[i].C = 1;
		}
		Fireball tmp = { v[i].R, v[i].C, v[i].W, v[i].S, v[i].D };
		grid[v[i].R][v[i].C].push_back(tmp);
	}

	v.clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (grid[i][j].size() >= 2) {
				int m = 0, s = 0, d = -1, chk_d = -1;
				if (grid[i][j][0].D % 2 == 0) chk_d = 0;
				else chk_d = 1;
				for (int k = 0; k < grid[i][j].size(); k++) {
					m += grid[i][j][k].W;
					s += grid[i][j][k].S;

					if (chk_d == 0 && grid[i][j][k].D % 2 != 0) chk_d = -1;
					else if (chk_d == 1 && grid[i][j][k].D % 2 == 0) chk_d = -1;
				}

				m /= 5, s /= grid[i][j].size();
				grid[i][j].clear();

				if (m == 0) continue;

				if (chk_d == 0 || chk_d == 1) d = 0;
				else d = 1;

				for (int k = 0; k < 4; k++) {
					Fireball tmp = { i, j, m, s, d };
					grid[i][j].push_back(tmp);
					d += 2;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (grid[i][j].size() > 0) {
				for (int k = 0; k < grid[i][j].size(); k++) {
					v.push_back(grid[i][j][k]);
				}

				grid[i][j].clear();
			}
		}
	}
}

int main() {

	cin >> N >> M >> K;

	int r = 0, c = 0, m = 0, s = 0, d = 0;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		Fireball tmp = { r, c, m ,s, d };
		v.push_back(tmp);
	}

	for (int i = 0; i < K; i++) {
		order();
	}

	for (int i = 0; i < v.size(); i++) {
		result += v[i].W;
	}

	cout << result << "\n";

	return 0;
}
