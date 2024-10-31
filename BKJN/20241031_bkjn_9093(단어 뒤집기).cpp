#include <iostream>
#include <string>
using namespace std;

int main(void) {

	int T = 0;

	cin >> T;
	cin.ignore();

	string str;

	for (int i = 0; i < T; i++) {
		getline(cin, str);

		int len = str.length();

		for (int j = 0; j < len; j++) {
			if (str[j] != ' ') {
				int word_len = 0;

				for (int k = j; k < len; k++) {
					if (str[k] == ' ') break;

					word_len++;
				}

				char tmp = 0;
				int a = j + word_len - 1, b = 0;

				for (int k = j; k < j + (word_len / 2); k++) {
					tmp = str[k];
					str[k] = str[a - b];
					str[a - b] = tmp;

					b++;
				}

				j += word_len - 1;
			}
		}

		cout << str << endl;

		str.clear();
	}

	return 0;
}

/*
string을 이용해서 풀었는데 중요한 점은
cin>>을 사용 한 후 getline을 사용하려면 입력버퍼에 있는 줄바꿈을 없애야 하기 때문에 cin.ignore()를 사용하고 getline을 사용해야 한다.
그리고 str.clear()를 사용하지 않아도 자동으로 str이 초기화가 되는데 이 이유는 공부를 해봐야 할 것 같다.
*/
