#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Binary_Tree {
private:
    Node* root;

    Node* Insert_Node(Node* cur, int val) {
        if (cur == NULL) {
            return new Node(val);
        }
        else if (val < cur->data) {
            cur->left = Insert_Node(cur->left, val);
        }
        else if (val > cur->data) {
            cur->right = Insert_Node(cur->right, val);
        }

        return cur;
    }

    void PostOrder(Node* cur) {
        if (cur == NULL) return;

        PostOrder(cur->left);
        PostOrder(cur->right);
        cout << cur->data << "\n";
    }

public:
    Binary_Tree() : root(NULL) {}

    void Insert(int val) {
        root = Insert_Node(root, val);
    }

    void Print_PostOrder() {
        PostOrder(root);
        cout << "\n";
    }
};

int main(void) {

    Binary_Tree tree;

    int x = 0;

    while (cin >> x) {
        tree.Insert(x);
    }

    tree.Print_PostOrder();

    return 0;
}

/*
클래스를 이용해서 이진탐색트리를 구현해봤다.
처음으로 클래스를 이용해서 트리를 만들어보았다.
전에는 이해가 잘 안됐던 부분이 이 문제를 풀면서 코드를 분석해보니 이해가 되었다.
특히 재귀부분이 잘 이해가 안갔는데 이제 명확해졌다.
*/
