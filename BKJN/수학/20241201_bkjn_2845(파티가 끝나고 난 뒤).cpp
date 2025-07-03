#include <vector>
#include <iostream>
using namespace std;

int main(void){
	int L, P;
	vector<int> numbers(5);

	cin >> L >> P;

	for (int i = 0; i < numbers.size(); i++)
		cin >> numbers[i];

	for (int num : numbers)
		cout << num - L * P << ' ';
}
