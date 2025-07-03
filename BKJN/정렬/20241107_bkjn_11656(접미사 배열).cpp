#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word;
    int len;

    cin >> word;
    len = word.length();
    string arr[1001];

    for (int i = 0; i < len; i++) {
        arr[i] = word.substr(i);
    }

    sort(arr, arr + len);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

/*
c++의 라이브러리 함수 sort와 substr의 사용법을 익힐 수 있는 문제였다.
편리한 함수들이 내장되어 있어서 코드를 쉽게 만들 수 있는 것 같다.
*/
