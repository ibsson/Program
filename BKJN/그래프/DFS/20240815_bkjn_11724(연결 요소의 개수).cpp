#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector <int> graph[MAX];
bool visited[MAX];

void DFS(int cur) {
	visited[cur] = true;

	for (int i = 0; i < graph[cur].size(); i++) {
		if (!visited[graph[cur][i]]) {
			DFS(graph[cur][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
			DFS(i);
		}
	}

	cout << cnt << '\n';

	return 0;
}

/*
#include <stdio.h>

int Vertex[1002][1002];
int Visited[1002];

void DFS(int index, int N) {

    Visited[index] = 1;

    for (int i = 1; i <= N; i++) {
        if (Vertex[index][i] == 1 && Visited[i] == 0) {
            DFS(i, N);
        }
    }
}

int main(void) {

    int N = 0, M = 0;

    scanf("%d %d", &N, &M);

    int V1 = 0, V2 = 0;

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &V1, &V2);

        Vertex[V1][V2] = 1;
        Vertex[V2][V1] = 1;
    }

    int cnt = 1;

    DFS(1, N);

    for (int i = 2; i <= N; i++) {
        if (Visited[i] == 0) {
            cnt++;
            DFS(i, N);
        }
    }

    printf("%d\n", cnt);

    return 0;
}

/*
처음에는 인접리스트와 분리집합을 이용해서 풀려고 했으나 시간초과로 실패를 했다.
그리고는 인접리스트와 DFS를 이용해서 풀려고 했으나 역시 시간초과로 실패를 했다.
이때 인접리스트를 쓰면 시간이 더 걸린다고 생각해서 인접행렬로 바꿨다.
인접행렬과 DFS를 이용해서 풀려고 했으나 배열 크기의 1을 작게 설정해서 조금 시간이 걸렸다.
이 문제를 통해서 알게 된 것은 걸리는 시간은 인접리스트보다 인접행렬이 더 빠르다는 사실을 알게 되었다.
그리고 항상 느끼는 것이지만 배열크기 설정을 잘 해야겠다..
*/
*/
