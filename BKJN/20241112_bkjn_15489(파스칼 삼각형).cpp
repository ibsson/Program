#include <iostream>
using namespace std;

int triangle[30][30] = { 0 };

int main(void) {

	int R = 0, C = 0, W = 0;

	cin >> R >> C >> W;
	triangle[1][1] = 1, triangle[2][1] = 1, triangle[2][2] = 1;

	for (int i = 3; i < (R + W); i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) triangle[i][j] = 1;
			else {
				triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
			}
		}
	}

	int tmp = 1, sum = 0;

	for (int i = R; i < (R + W); i++) {
		for (int j = C; j < C + tmp; j++) {
			sum += triangle[i][j];
		}
		tmp++;
	}

	cout << sum << endl;

	return 0;
}
