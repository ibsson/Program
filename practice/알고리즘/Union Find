#include <iostream>
using namespace std;

int parent[10];

int find_parent(int x) {
	if (parent[x] != x) {
		return parent[x] = find_parent(parent[parent[x]]);
	}
	
	return x;
}

void merge(int a, int b) {
	int x = find_parent(a);
	int y = find_parent(b);

	if (x != y) {
		if (x < y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}
}
