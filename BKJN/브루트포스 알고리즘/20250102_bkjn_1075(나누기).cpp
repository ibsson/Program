#include <iostream>
using namespace std;

int main(void) {
	int N = 0, F = 0;
	int answer = 0;
	cin >> N >> F;
	
	N /= 100;
	N *= 100;
	
	while((N+answer) % F != 0 && answer < 100) answer++;
	
	if(answer < 10) cout << "0" << answer;
	else cout << answer;
	
}
