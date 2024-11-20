#include <iostream>
using namespace std;

int main(void) {

	double X = 0, Y = 0;

	cin >> X >> Y;

	int i = 0;
	int ori = Y * 100 / X;

	if (ori >= 99) {
		cout << "-1\n";
		return 0;
	}

	int left = 0, right = 1000000000, mid = 0, result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int tmp = ((Y + mid) * 100) / (X + mid);

		if (tmp > ori) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << result << endl;

	return 0;
}

/*
계속해서 실수형 계산과 정수형 계산 때문에 문제가 발생해서
실수형 계산과 정수형 계산을 잘 구분해서 해야겠다는 생각이 든 문제였다.
*/
