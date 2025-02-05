#include <iostream>
#include <vector>
using namespace std;

int N, M;
int result = 1000000;
vector <pair<int, int>> house;
vector <pair<int, int>> chicken;
vector <pair<int, int>> sel;

void getResult() {
	int sum = 0;

	for (int i = 0; i < house.size(); i++) {
		int min_sum = 1000000;

		for (int j = 0; j < sel.size(); j++) {
			min_sum = min(min_sum, abs(house[i].first - sel[j].first) + abs(house[i].second - sel[j].second));
		}

		sum += min_sum;
	}

	result = min(result, sum);
}

void selectChicken(int idx, int cnt) {
	if (cnt == M) {
		getResult();
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		sel.push_back({ chicken[i].first, chicken[i].second });
		selectChicken(i + 1, cnt + 1);
		sel.pop_back();
	}
}

int main() {

	cin >> N >> M;

	int x = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;

			if (x == 1) house.push_back({ i, j });
			else if (x == 2) chicken.push_back({ i, j });
		}
	}

	selectChicken(0, 0);

	cout << result << "\n";

	return 0;
}
