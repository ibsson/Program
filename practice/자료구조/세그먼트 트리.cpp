#include <iostream>
#include <vector>
#define NUMBER 5
using namespace std;

int a[] = { 1, 2, 3, 4, 5 };
int tree[4 * NUMBER];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, (node * 2) + 1);
}

int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, (node * 2) + 1, left, right);
}

void update(int start, int end, int node, int idx, int dif) {
	if (idx < start || idx > end) return;

	tree[node] += dif;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, (node * 2) + 1, idx, dif);
}

int main() {
	init(0, NUMBER - 1, 1);

	cout << "0부터 4까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 4) << '\n';
	cout << "2부터 4까지의 구간 합: " << sum(0, NUMBER - 1, 1, 2, 4) << '\n';
	cout << "인덱스 4의 원소를 -4만큼 수정" << '\n';
	update(0, NUMBER - 1, 1, 4, -4);
	cout << "2부터 4까지의 구간 합: " << sum(0, NUMBER - 1, 1, 2, 4) << '\n';
 
	return 0;
}
