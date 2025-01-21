#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string A, B;

	cin >> A >> B;

	int A_min = 0, B_min = 0, min_result = 0;

	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '6') A[i] = '5';
	}
	A_min = stoi(A);

	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '6') B[i] = '5';
	}
	B_min = stoi(B);

	min_result = A_min + B_min;

	int A_max = 0, B_max = 0, max_result = 0;

	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '5') A[i] = '6';
	}
	A_max = stoi(A);

	for (int i = 0; i < B.length(); i++) {
		if (B[i] == '5') B[i] = '6';
	}
	B_max = stoi(B);

	max_result = A_max + B_max;

	cout << min_result << " " << max_result << "\n";

	return 0;
}
