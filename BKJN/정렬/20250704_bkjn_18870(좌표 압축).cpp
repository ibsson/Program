#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001

typedef struct info {
	int data;
	int idx;
}info;

info num[MAX];
int res[MAX];

bool compare(info a, info b) {
	return (a.data < b.data);
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		num[i] = { x, i };
	}

	sort(num, num + N, compare);

	int cnt = -1, tmp = -1;

	for (int i = 0; i < N; i++) {
		if (tmp != num[i].data) {
			tmp = num[i].data;
			cnt++;
		}

		res[num[i].idx] = cnt;
	}

	for (int i = 0; i < N; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';

	return 0;
}
