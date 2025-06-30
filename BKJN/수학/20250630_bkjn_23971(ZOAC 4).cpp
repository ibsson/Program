#include <iostream>
using namespace std;

int main() {

	int H, W, N, M;

	cin >> H >> W >> N >> M;

	int cnt_H = 1, cnt_W = 1;
	int tmp_H = 0, tmp_W = 0;

	while (cnt_H <= H) {
		cnt_H += (N + 1);
		tmp_H++;
	}

	while (cnt_W <= W) {
		cnt_W += (M + 1);
		tmp_W++;
	}

	cout << tmp_H * tmp_W;

	return 0;
}
