#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Compare(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length(); //길이가 다르면 짧은거 순서대로 정렬
	}

	if (s1.length() == s2.length()) {
		int cnt_1 = 0, cnt_2 = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (isdigit(s1[i])) {
				cnt_1 += s1[i] - '0';
			}

			if (isdigit(s2[i])) {
				cnt_2 += s2[i] - '0';
			}
		}

		if (cnt_1 != cnt_2) return cnt_1 < cnt_2; //길이가 같으면 숫자인 자리수들의 합이 작은거 순서대로 정렬

		return s1 < s2; //길이도 같고 숫자인 자리수들의 합도 같다면 사전순으로 정렬
	}
}

int main(void) {

	string str[51];
	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	sort(str, str + N, Compare);

	for (int i = 0; i < N; i++) {
		cout << str[i] << endl;
	}

	return 0;
}

/*
string class와 sort함수를 이용해서 만들었다.
sort함수를 사용할때 Compare함수를 문제에 조건에 맞게 어떻게 만들어야 할지 감이 안잡혔는데 이 문제를 통해서 어떻게 만들어야 하는지 감이 잡힌 것 같다.
앞으로 잘 활용해서 문제풀때 유용하게 사용해야겠다.
*/
