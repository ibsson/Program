#include <iostream>
#include <math.h>
using namespace std;

int main() {

	int D = 0, H = 0, W = 0;

	cin >> D >> H >> W;

	int h = H * (sqrt(pow(D, 2) / (pow(H, 2) + pow(W, 2))));
	int w = W * (sqrt(pow(D, 2) / (pow(H, 2) + pow(W, 2))));

	cout << h << " " << w << "\n";

	return 0;
}
