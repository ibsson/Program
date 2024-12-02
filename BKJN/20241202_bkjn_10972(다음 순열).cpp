#include <iostream>
#include <algorithm>
using namespace std;

int chk;
int arr[10001];
int result[10001];

int main(void) {

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int tmp = 0;

	for (int i = (N - 1); i > 0; i--) {
		if (arr[i] > arr[i - 1]) {
			chk = 1;
			for (int j = (N - 1); j >= (i - 1); j--) {
				if (arr[j] > arr[i - 1]) {
					tmp = arr[j];
					arr[j] = arr[i - 1];
					arr[i - 1] = tmp;
					sort(arr + i, arr + N);
					break;
				}
			}
		}
		if (chk) break;
	}

	if (!chk) {
		cout << "-1" << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
