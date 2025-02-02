#include <iostream>
#include <math.h>
using namespace std;

int N, W, H;

int main() {

	cin >> N >> W >> H;

	double tmp = sqrt(pow(W, 2) + pow(H, 2));

	double len = 0;
	for (int i = 0; i < N; i++) {
		cin >> len;

		if (len <= W && len <= H) cout << "DA\n";
		else if (len <= tmp) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}
