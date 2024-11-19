#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void) {

	int T = 0;
	double x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2) {
			if (r1 != r2) {
				cout << "0\n";
				continue;
			}
			else {
				cout << "-1\n";
				continue;
			}
		}

		double len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if (len < max(r1, r2)) { //중심이 원 안에 있을때
			if (max(r1, r2) < min(r1, r2) + len) {
				cout << "2\n";
			}
			else if (max(r1, r2) == min(r1, r2) + len) {
				cout << "1\n";
			}
			else if (max(r1, r2) > min(r1, r2) + len) {
				cout << "0\n";
			}
		}
		else { //중심이 원 밖에 있을때
			if ((r1 + r2) > len) {
				cout << "2\n";
			}
			else if ((r1 + r2) == len) {
				cout << "1\n";
			}
			else if ((r1 + r2) < len) {
				cout << "0\n";
			}
		}
	}

	return 0;
}

/*
옛날에 풀었을때 손도 못대고 포기했었던 문제였다.
하지만 지금은 조금 생각하니 금방 풀렸다.
옛날보다 많이 성장했다는게 느껴져서 기분이 좋았다.
좌표는 중심축으로 생각하고 거리를 반지름으로 가지는 원이라고 생각하고 조건만 잘 나누면 쉽게 풀리는 문제였다.
*/
