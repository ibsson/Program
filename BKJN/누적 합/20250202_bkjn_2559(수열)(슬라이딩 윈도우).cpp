#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector <int> temperature;

int main() {

	cin >> N >> K;

	int x = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;

		temperature.push_back(x);
	}

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += temperature[i];
	}

	int result = sum;

	for (int i = K; i < N; i++) {
		sum += temperature[i];
		sum -= temperature[i - K];
		result = max(result, sum);
	}

	cout << result << "\n";

	return 0;
}
