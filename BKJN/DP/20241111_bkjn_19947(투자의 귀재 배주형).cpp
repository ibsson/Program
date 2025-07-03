#include <iostream>
using namespace std;

int a = 0;

void Get_Result(int, int);

int main(void) {

	int H = 0, Y = 0;

	cin >> H >> Y;

	Get_Result(H, Y);

	cout << a << endl;

	return 0;
}

void Get_Result(int H, int Y) {

	if (Y == 0) {
		if (a < H) {
			a = H;
		}
		return;
	}

	if ((Y - 1) >= 0) {
		Get_Result(H * 1.05, Y - 1);
	}
	if ((Y - 3) >= 0) {
		Get_Result(H * 1.2, Y - 3);
	}
	if ((Y - 5) >= 0) {
		Get_Result(H * 1.35, Y - 5);
	}
}

/*
이 문제는 top-down 방식으로 풀었다.
dp와 브루트포스를 같이 활용하는 문제인 것 같다.
스스로 풀어낸 재귀함수 문제라서 뿌듯하다.
더 코드를 깔끔하게 만들 수 있을 것 같다.
*/
