#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector <int> price;

int main(void) {

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		
		int x = 0, max_price = 0;

		for (int i = 0; i < N; i++) {
			cin >> x;

			price.push_back(x);
		}

		int tmp = price[N - 1];
		long long int sum = 0;

		for (int i = (N - 2); i >= 0; i--) {
			if (tmp > price[i]) sum += (tmp - price[i]);
			else tmp = price[i];
		}

		cout << sum << "\n";

		price.clear();
	}

	return 0;
}
