#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 100001

int n, farthestNode;
int maxDist = 0;
bool visited[MAX];
vector <pair<int, int>> tree[MAX];

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        int nextNode = tree[node][i].first;
        int nw = tree[node][i].second;

        if (!visited[nextNode]) {
            dfs(nextNode, (dist + nw));
        }
    }
}

int main(void) {

    cin >> n;

    int from = 0, to = 0, w = 0;

    for (int i = 0; i < (n - 1); i++) {
        cin >> from >> to >> w;

        tree[from].push_back({ to, w });
        tree[to].push_back({ from, w });
    }

    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    dfs(farthestNode, 0);

    cout << maxDist << "\n";

    return 0;
}
