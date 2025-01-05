#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10010

int n, ans;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];

int dfs(int x) {
    visited[x] = true;

    int len1 = 0, len2 = 0;
    for (auto& edge : tree[x]) {
        int next = edge.first, weight = edge.second;

        if (!visited[next]) {
            int dist = dfs(next) + weight;

            if (dist > len1) {
                len2 = len1;
                len1 = dist;
            }
            else if (dist > len2) {
                len2 = dist;
            }
        }
    }

    ans = max(ans, len1 + len2);
    return len1;
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;

        tree[p].push_back({ c, w });
        tree[c].push_back({ p, w });
    }

    fill(visited, visited + (n + 1), false);
    dfs(1);
    fill(visited, visited + (n + 1), false);

    int farthest = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] && dfs(i) > ans) {
            farthest = i;
        }
    }

    fill(visited, visited + (n + 1), false);
    dfs(farthest);

    cout << ans << "\n";
    return 0;
}
