#include <iostream>
using namespace std;

int main() {

    string str;
    cin >> str;
    
    while (str.length() % 3 != 0) {
        str = '0' + str; //3자리씩 끊었을때 나누어 떨어지지 않는다면 문자열 맨 앞에 0붙이기
    }

    for (int i = 0; i < str.length(); i += 3) {
        int num = (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0') * 1;
        cout << num;
    }

    return 0;
}
