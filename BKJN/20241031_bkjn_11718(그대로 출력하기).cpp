#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;

	while(1) {
		getline(cin, s);
		if(s == "") break;

		cout << s << '\n';
	}

	return 0;
}

/*
문제 조건을 제대로 이해 못해서 쉬운 문제임에도 불구하고 시간이 걸렸다.
아무것도 입력하지 않았을때 프로그램이 끝나는 것으로 설정해서 풀었다.
*/
