#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TrieNode {
    bool isEndOfWord;
    TrieNode* children[10]; // 전화번호는 숫자로만 구성됨 (0-9)

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 10; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void clear(TrieNode* node) {
        for (int i = 0; i < 10; i++) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        delete node;
    }

    // 전화번호를 Trie에 삽입
    bool insert(string number) {
        TrieNode* node = root;

        for (char ch : number) {
            int idx = ch - '0';

            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            // 현재 노드가 다른 번호의 끝이면 접두어 충돌 발생
            if (node->isEndOfWord) return false;
        }
        // 현재 번호를 삽입했는데 하위에 다른 번호가 있으면 접두어 충돌 발생
        for (int i = 0; i < 10; i++) {
            if (node->children[i]) return false;
        }
        node->isEndOfWord = true;

        return true;
    }
};

bool isConsistent(vector<string> phoneNumbers) {
    Trie trie;

    for (string number : phoneNumbers) {
        if (!trie.insert(number)) {
            return false; // 접두어 충돌 발생
        }
    }

    return true; // 모든 번호가 일관됨
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> phoneNumbers(n);

        for (int i = 0; i < n; i++) {
            cin >> phoneNumbers[i];
        }

        sort(phoneNumbers.begin(), phoneNumbers.end());

        if (isConsistent(phoneNumbers)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*
자료구조 TRIE를 처음 만들어보았다.
트리와 유사한 자료구조여서 구조를 이해하는것은 쉬웠다.
하지만 아직 익숙치 않아서 완전히 이해하고 활용하려면 조금 더 이 자료구조를 만드는데 연습이 필요할 것 같다.
  
TRIE는 문자열을 저장하고 탐색하는데 효율적인 자료구조이다.
트라이(Trie)는 문자열 검색을 빠르게 한다.
문자열을 탐색할 때, 하나하나씩 전부 비교하면서 탐색을 하는 것보다 시간 복잡도 측면에서 훨씬 더 효율적이다.

앞으로 문자열 관련 문제가 나올때 활용해보면서 연습해봐야겠다.
*/
