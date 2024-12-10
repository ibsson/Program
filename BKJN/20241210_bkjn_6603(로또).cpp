#include <iostream>
using namespace std;

int k;
int num[14];
int visited[14];
int result[7];

void Get_Result(int cnt, int idx) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i < k; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			result[cnt] = num[i];
			Get_Result((cnt + 1), i);
			visited[i] = 0;
		}
	}
}

int main(void) {

	while (1) {

		cin >> k;

		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}

		Get_Result(0, 0);

		cout << "\n";
	}

	return 0;
}
