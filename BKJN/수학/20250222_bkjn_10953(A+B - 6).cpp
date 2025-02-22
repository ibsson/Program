#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int a = 0, b = 0, c = 0;
	char comma;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> comma >> b;
		c = a + b;
		cout << c << "\n";
	}
    
    return 0;
}
