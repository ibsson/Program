#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> lectures;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start = 0, end = 0;
        cin >> start >> end;
        lectures.push_back({ start, end });
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(lectures[0].second);

    for (int i = 1; i < N; i++) {
        if (lectures[i].first >= pq.top()) {
            pq.pop();
        }
        pq.push(lectures[i].second);
    }

    cout << pq.size() << "\n";

    return 0;
}

/*
이런 그리디 문제에서 우선순위 큐가 굉장히 유용하게 쓰일 것 같다는 생각이 들었고,
앞으로 그리디 문제를 풀 때 많이 활용해봐야겠다고 생각했다.
*/
