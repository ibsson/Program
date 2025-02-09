#include <iostream>
using namespace std;

#define MAX 501

int H, W, result;
int arr[MAX];

int main() {

	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < (W - 1); i++) {
		int left = 0, right = 0;

		for (int j = i; j >= 0; j--) {
			left = max(left, arr[j]);
		}
		for (int j = i; j < W; j++) {
			right = max(right, arr[j]);
		}

		int tmp = min(left, right);

		if (tmp > arr[i]) result += tmp - arr[i];
	}

	cout << result << "\n";

	return 0;
}
