#include <iostream>
using namespace std;

int N;
int _size[6];
int T, P;
int t_cnt, p_cnt1, p_cnt2;

int main(void) {

	cin >> N;
	cin >> _size[0] >> _size[1] >> _size[2] >> _size[3] >> _size[4] >> _size[5];
	cin >> T >> P;

	for (int i = 0; i < 6; i++) {
		if (_size[i] % T == 0) {
			t_cnt += _size[i] / T;
		}
		else {
			t_cnt += (_size[i] / T) + 1;
		}
	}

	p_cnt1 = (N / P);
	p_cnt2 = (N % P);

	cout << t_cnt << "\n";
	cout << p_cnt1 << " " << p_cnt2 << "\n";

	return 0;
}
