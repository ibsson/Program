#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
char shark[10];
bool visited[10];
vector <int> v;
string Min = "999999999";
string Max = "0";

void backTracking(int idx) {

	if (idx == k) {
		string result = "";
		for (int num : v) {
			result += to_string(num);
		}

		if (result < Min) Min = result;
		if (result > Max) Max = result;

		return;
	}

	switch (shark[idx]) {
	case '<':
		for (int i = 0; i <= 9; i++) {
			if (!visited[i]) {
				if (v[idx] < i) {
					visited[i] = true;
					v.push_back(i);
					backTracking(idx + 1);
					visited[i] = false;
					v.pop_back();
				}
			}
		}
		break;
	case '>':
		for (int i = 0; i <= 9; i++) {
			if (!visited[i]) {
				if (v[idx] > i) {
					visited[i] = true;
					v.push_back(i);
					backTracking(idx + 1);
					visited[i] = false;
					v.pop_back();
				}
			}
		}
		break;
	}
}

int main(void) {

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> shark[i];
	}

	for (int i = 0; i <= 9; i++) {
		v.push_back(i);
		visited[i] = true;
		backTracking(0);
		v.pop_back();
		visited[i] = false;
	}

	cout << Max << "\n";
	cout << Min << "\n";

	return 0;
}

/*
정수형을 문자열로 바꿔서 최대 최소를 비교하는게 어려워서 조금 헤맸다.
이 문제를 통해서 숫자를 문자열로 바꿔서 최대 최소를 비교하는 방법을 알게되었다.
*/
