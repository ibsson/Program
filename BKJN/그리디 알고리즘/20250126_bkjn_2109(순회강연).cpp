#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector <pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {

	cin >> n;

	if (n == 0) {
		cout << "0\n";
		return 0;
	}

	int p = 0, d = 0;

	for (int i = 0; i < n; i++) {
		cin >> p >> d;

		v.push_back({ p,d });
	}

	sort(v.begin(), v.end(), compare);

	priority_queue<int, vector<int> , greater<int>> pq;
	pq.push(v[0].first);
	
	for (int i = 1; i < v.size(); i++) {
		if (pq.size() >= v[i].second) {
			if (pq.top() < v[i].first) {
				pq.pop();
				pq.push(v[i].first);
			}
		}
		else {
			pq.push(v[i].first);
		}
	}

	int result = 0;

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	cout << result << "\n";

	return 0;
}

/*
골드 등급 이상의 그리디 문제를 내 스스로 처음으로 풀어냈다.
우선순위큐를 이용해서 풀었다.
내 기준으로 어렵다고 생각되는 그리디 유형의 골드 등급의 문제를 내 힘으로 풀어냈다.
정말 정말 기분이 좋았고 점점 그리디 문제를 푸는 감이 잡히는 것 같다.
문제를 풀기 전에 틀을 잡고 푸는것이 정말 중요하다고 요즘 문제를 풀면서 느낀다.
틀을 잡는 연습의 필요성을 깊게 느꼈다.
더 열심히 해서 더 빠르고 좋은 코드를 만들고 싶고 더 잘하고 싶다.
*/
