#include <iostream>
#include <string.h>
using namespace std;

int student[1000][5] = { 0 };
int sum[1001] = { 0 };
int check[1001] = { 0 };

int main(void) {

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> student[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < n; k++) {
				if (i == k) continue;

				if (student[i][j] == student[k][j] && check[k] == 0) {
					sum[i]++;
					check[k] = 1;
				}
			}
		}
		memset(check, 0, sizeof(check));
	}

	int max = -1, index = 0;

	for (int i = 0; i < n; i++) {
		if (max < sum[i]) {
			max = sum[i];
			index = (i + 1);
		}
	}

	cout << index << endl;
	
	return 0;
}
