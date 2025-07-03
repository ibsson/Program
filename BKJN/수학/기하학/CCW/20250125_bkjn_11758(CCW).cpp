#include <iostream>
using namespace std;

int P1[2];
int P2[2];
int P3[2];
int A[2];
int B[2];

int main(void) {

	cin >> P1[0] >> P1[1];
	cin >> P2[0] >> P2[1];
	cin >> P3[0] >> P3[1];

	A[0] = P2[0] - P1[0], A[1] = P2[1] - P1[1];
	B[0] = P3[0] - P2[0], B[1] = P3[1] - P2[1];

	int result = (A[0] * B[1]) - (A[1] * B[0]);

	if (result > 0) cout << "1\n";
	else if (result == 0) cout << "0\n";
	else cout << "-1\n";

	return 0;
}
