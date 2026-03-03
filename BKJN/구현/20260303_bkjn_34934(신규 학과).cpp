#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string, int> m;
vector <pair<string, int>> v;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

int main(void) {
	int N;
	cin >> N;

	string n;
	int y;
	for (int i = 0; i < N; i++) {
		cin >> n >> y;
		m.insert(make_pair(n, y));
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		v.push_back(make_pair(it->first, it->second));
	}

	sort(v.begin(), v.end(), cmp);

	cout << v.begin()->first << "\n";
	
	return 0;
}
