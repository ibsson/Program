#include <iostream>
using namespace std;

struct TRIE {
	bool finish;
	TRIE* Node[26];
	TRIE() {
		finish = false;
		for (int i = 0; i < 26; i++) {
			Node[i] = NULL;
		}
	}

	void Insert(const char* str);
	void IsSorting(TRIE* N, char str[], int idx);
	bool Find(char* str);
};

void TRIE::Insert(const char* str) {
	if ((*str) == NULL) {
		finish = true;
		return;
	}

	int cur = (*str) - 'A';
	if (Node[cur] == NULL) Node[cur] = new TRIE();
	Node[cur]->Insert(str + 1);
}

void TRIE::IsSorting(TRIE* N, char str[], int idx) {
	if (N->finish == true) cout << str << endl;
	for (int i = 0; i < 26; i++) {
		if (N->Node[i] != NULL) {
			char C = i + 'A';
			str[idx] = C;
			N->IsSorting(N->Node[i], str, idx + 1);
		}
	}
}

bool TRIE::Find(char* str) {
	if ((*str) == NULL) {
		if (finish == true) return true;
		return false;
	}
	int cur = (*str) - 'A';
	if (Node[cur] == NULL) return false;
	return Node[cur]->Find(str + 1);
}

int main() {
	TRIE* Root = new TRIE();
	const char* str[5];
	str[0] = "ZYX";
	str[1] = "BCG";
	str[2] = "ABC";
	str[3] = "BDE";
	str[4] = "ABCD";

	for (int i = 0; i < 5; i++) {
		Root->Insert(str[i]);
	}

	for (int i = 0; i < 26; i++) {
		if (Root->Node[i] != NULL) {
			char str[5] = { NULL };
			str[0] = i + 'A';
			Root->IsSorting(Root->Node[i], str, 1);
		}
	}

	return 0;
}
