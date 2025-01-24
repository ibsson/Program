#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, result;
vector <int> sensor;
vector <int> dist;

int main(void) {

	cin >> N;
	cin >> K;

	int x = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;

		sensor.push_back(x);
	}

	sort(sensor.begin(), sensor.end());

	for (int i = 0; i < (N - 1); i++) {
		int dif = sensor[i + 1] - sensor[i];
		dist.push_back(dif);
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < (N - 1) - (K - 1); i++) {
		result += dist[i];
	}

	cout << result << "\n";

	return 0;
}
