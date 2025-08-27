#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
vector <int> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;

	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		sum += tmp;
	}

	sort(v.begin(), v.end());

	int tmp = 0;
	int n1, n2;
	bool chk = false;
	for (int i = 0; i < 8; i++) {
		tmp += v[i];
		for (int j = (i + 1); j < 9; j++) {
			tmp += v[j];

			if (sum - tmp == 100) {
				n1 = i, n2 = j;
				chk = true;
				break;
			}
			else {
				tmp -= v[j];
			}
		}
		if (chk) break;

		tmp -= v[i];
	}

	for (int i = 0; i < 9; i++) {
		if (i == n1 || i == n2) continue;

		cout << v[i] << ' ';
	}
	cout << '\n';

	return 0;
}

/*
#Sol_2(function)_____________________________________________________________________________________________________________________________________________

#include <stdio.h>

int height[9] = { 0 };
int result[7] = { 0 };

void quicksort(int L, int R) {

	int left = L;
	int right = R;
	int pivot = height[((L + R) / 2)];
	int room = 0;

	do {
		while (height[left] < pivot) left++;

		while (height[right] > pivot) right--;

		if (left <= right) {
			room = height[left];
			height[left] = height[right];
			height[right] = room;
			left++;
			right--;
		}

	} while (left <= right);

	if (L < right) quicksort(L, right);

	if (left < R) quicksort(left, R);

}

void get_7_height() {

	int sum = 0, cnt = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = (i + 1); j < 9; j++) {
			for (int k = 0; k < 9; k++) {

				if (k == i || k == j) continue;

				sum += height[k];
				result[cnt] = height[k];
				cnt++;
			}

			if (sum == 100) {
				return;
			}
			else {
				for (int l = 0; l < 7; l++) {
					result[l] = 0;
				}
			}

			sum = 0;
			cnt = 0;
		}
	}
}

int main(void) {

	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	quicksort(0, 8);

	get_7_height();

	for (int i = 0; i < 7; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}
	
#Sol_1_______________________________________________________________________________________________________________________________________________________

#include <stdio.h>

int height[9] = { 0 };

void quicksort(int L, int R) {

	int left = L;
	int right = R;
	int pivot = height[((L + R) / 2)];
	int room = 0;

	do {
		while (height[left] < pivot) left++;

		while (height[right] > pivot) right--;

		if (left <= right) {
			room = height[left];
			height[left] = height[right];
			height[right] = room;
			left++;
			right--;
		}

	} while (left <= right);

	if (L < right) quicksort(L, right);

	if (left < R) quicksort(left, R);

}

int main(void) {

	int sum = 0, cnt = 0;
	int result[7] = { 0 };

	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	quicksort(0, 8);

	for (int i = 0; i < 8; i++) {
		for (int j = (i + 1); j < 9; j++) {
			for (int k = 0; k < 9; k++) {

				if (k == i || k == j) continue;

				sum += height[k];
				result[cnt] = height[k];
				cnt++;
			}

			if (sum == 100) {
				for (int l = 0; l < 7; l++) {
					printf("%d\n", result[l]);
				}
				return 0;
			}
			else {
				for (int l = 0; l < 7; l++) {
					result[l] = 0;
				}
			}

			sum = 0;
			cnt = 0;
		}
	}

	return 0;
}
*/
