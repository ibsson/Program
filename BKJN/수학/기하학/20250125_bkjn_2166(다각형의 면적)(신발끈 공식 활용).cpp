#include <iostream>
#include <vector>
using namespace std;

int N;
vector <pair<int, int>> pos;

long double solve(int i, int j) {
	long double a = pos[0].first, b = pos[0].second;
	long double c = pos[i].first, d = pos[i].second;
	long double e = pos[j].first, f = pos[j].second;

	return ((a * d + c * f + e * b) - (c * b + e * d + a * f)) / 2;
}

int main(void) {

	cin >> N;

	double x = 0, y = 0;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		pos.push_back({ x, y });
	}

	long double result = 0.0;

	for (int j = 1; j < pos.size() - 1; j++) {
		result += solve(j, j + 1);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(result) << "\n";

	return 0;
}
