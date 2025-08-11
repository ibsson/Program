#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Trie {
	map<string, Trie*> m;

	void Insert(vector<string>& v, int idx);
	void DFS(int d);
};

void Trie::Insert(vector<string>& v, int idx) {
	if (idx == v.size()) {
		return;
	}

	if (m.find(v[idx]) == m.end()) {
		Trie* trie = new Trie;
		m.insert({ v[idx], trie });
	}

	m[v[idx]]->Insert(v, idx + 1);
}

void Trie::DFS(int d) {
	for (auto& i : m) {
		for (int j = 0; j < d; j++) {
			cout << "--";
		}
		cout << i.first << '\n';
		i.second->DFS(d + 1);
		delete i.second;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	Trie* root = new Trie;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;

		vector<string> v(K);
		for (int j = 0; j < K; j++) {
			cin >> v[j];
		}
		root->Insert(v, 0);
	}

	root->DFS(0);
	delete root;

	return 0;
}
