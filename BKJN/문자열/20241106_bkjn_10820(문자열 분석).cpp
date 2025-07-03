#include <iostream>
#include <string>
using namespace std;

void check_str(string);

int main(void) {

	string str;

	while (getline(cin, str)) {
		check_str(str);
	}

	return 0;
}

void check_str(string str) {

	int cnt[4] = { 0 };

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			cnt[0]++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			cnt[1]++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			cnt[2]++;
		}
		else if (str[i] >= ' ') {
			cnt[3]++;
		}
	}

	cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
}

/*
c++로 EOF를 어떻게 처리하는지 몰라서 조금 헤맸다.
방법은 반복조건 안에 getline함수를 넣어서 EOF까지 입력받게 했다.
EOF를 사용하는 문제가 나오면 이 방법을 잘 활용하면 좋을 것 같다.
*/
