#include <iostream>
using namespace std;

int main(void) {

	int N = 0, L = 0;

	cin >> N >> L;

	while (1) {
		int a = (N / L) - (L - 1) / 2;

		if (a < 0 || L > 100) {
			cout << "-1\n";
			break;
		}

		int tmp = 0;

		for (int i = a; i < (a + L); i++) {
			tmp += i;
		}

		if (tmp == N) {
			for (int i = 0; i < L; i++) {
				cout << a << " ";
				a++;
			}
			cout << endl;
			break;
		}
		else L++;
	}

	return 0;
}

/*
이 문제는 등차수열의 합 공식을 사용해서 풀었다.
내 스스로 푼 꽤 어려운 문제라서 뿌듯했다.
*/
