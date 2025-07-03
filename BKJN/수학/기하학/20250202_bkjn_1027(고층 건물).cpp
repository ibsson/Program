#include <iostream>
#include <vector>
using namespace std;

#define MAX 51

int N, result;
vector<pair<double, double>> pos;
int cnt[MAX];

int main() {

	cin >> N;

	double y = 0;
	for (double x = 1; x <= N; x++) {
		cin >> y;

		pos.push_back({ x, y });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			int chk = 1;

			if (j < i) {
				for (int k = (i - 1); k > j; k--) {
					double incline = (pos[j].second - pos[i].second) / (pos[j].first - pos[i].first);
					double x = incline * (pos[k].first - pos[i].first) + pos[i].second;
					if (x <= pos[k].second) {
						chk = 0;
						break;
					}
				}
			}
			else if (j > i) {
				for (int k = (i + 1); k < j; k++) {
					double incline = (pos[j].second - pos[i].second)/ (pos[j].first - pos[i].first);
					double x = incline * (pos[k].first - pos[i].first) + pos[i].second;
					if (x <= pos[k].second) {
						chk = 0;
						break;
					}
				}
			}

			if (chk) cnt[i]++;
		}

		result = max(result, cnt[i]);
	}

	cout << result << "\n";

	return 0;
}
