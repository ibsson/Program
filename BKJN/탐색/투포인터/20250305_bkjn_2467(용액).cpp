#include <iostream>
#include <climits>
using namespace std;

int N, com = INT_MAX;
int arr[100001];
int result[2];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0, right = (N - 1);
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) < com) {
			com = abs(sum);
			result[0] = arr[left], result[1] = arr[right];
		}

		if (sum < 0) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << result[0] << " " << result[1] << "\n";

	return 0;
}
