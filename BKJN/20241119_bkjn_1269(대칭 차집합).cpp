#include <iostream>
#include <algorithm>
using namespace std;

int A[200001] = { 0 };
int B[200001] = { 0 };

int BinarySearch(int num[], int N, int Target);

int main(void) {

	int n = 0, m = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	sort(A, A + n);
	sort(B, B + m);

	int cnt_1 = 0;

	for (int i = 0; i < n; i++) {
		if (BinarySearch(B, m, A[i]) != -1) cnt_1++;
	}

	int cnt_2 = 0;

	for (int i = 0; i < m; i++) {
		if (BinarySearch(A, n, B[i]) != -1) cnt_2++;
	}

	cout << (n - cnt_1) + (m - cnt_2) << endl;

	return 0;
}

int BinarySearch(int num[], int N, int Target) {

	int Left = 0, Right = 0, Mid = 0;

	Right = N - 1;

	while (Left <= Right) {
		Mid = (Left + Right) / 2;

		if (Target == num[Mid]) return Mid;
		else if (Target > num[Mid]) Left = Mid + 1;
		else Right = Mid - 1;
	}

	return -1;
}
