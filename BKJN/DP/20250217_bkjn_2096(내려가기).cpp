#include <iostream>
#include <climits>
using namespace std;

#define MAX 100001

int N, max_result = -1, min_result = INT_MAX;
int arr[MAX][3];
int compare[3];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	compare[0] = arr[0][0], compare[1] = arr[0][1], compare[2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		int tmp[3] = { 0, 0, 0 };

		tmp[0] = max(tmp[0], compare[0] + arr[i][0]);
		tmp[1] = max(tmp[1], compare[0] + arr[i][1]);

		tmp[0] = max(tmp[0], compare[1] + arr[i][0]);
		tmp[1] = max(tmp[1], compare[1] + arr[i][1]);
		tmp[2] = max(tmp[2], compare[1] + arr[i][2]);
		
		tmp[1] = max(tmp[1], compare[2] + arr[i][1]);
		tmp[2] = max(tmp[2], compare[2] + arr[i][2]);

		compare[0] = tmp[0], compare[1] = tmp[1], compare[2] = tmp[2];
	}

	for (int i = 0; i < 3; i++) {
		max_result = max(max_result, compare[i]);
	}

	compare[0] = arr[0][0], compare[1] = arr[0][1], compare[2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		int tmp[3] = { INT_MAX, INT_MAX, INT_MAX };

		tmp[0] = min(tmp[0], compare[0] + arr[i][0]);
		tmp[1] = min(tmp[1], compare[0] + arr[i][1]);

		tmp[0] = min(tmp[0], compare[1] + arr[i][0]);
		tmp[1] = min(tmp[1], compare[1] + arr[i][1]);
		tmp[2] = min(tmp[2], compare[1] + arr[i][2]);

		tmp[1] = min(tmp[1], compare[2] + arr[i][1]);
		tmp[2] = min(tmp[2], compare[2] + arr[i][2]);

		compare[0] = tmp[0], compare[1] = tmp[1], compare[2] = tmp[2];
	}

	for (int i = 0; i < 3; i++) {
		min_result = min(min_result, compare[i]);
	}

	cout << max_result << " " << min_result << "\n";

	return 0;
}
