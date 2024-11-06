#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    string str1 = to_string(A) + to_string(B);
    string str2 = to_string(C) + to_string(D);

    cout << stoll(str1) + stoll(str2) << endl;

    return 0;
}

/*
c++의 string library 함수를 사용해봤다.
처음에는 문자열을 숫자로 바꿔주는 함수인 stoi함수를 썼지만 stoi함수는 int로 변환시키기 때문에
범위를 넘어가버려 런타임에러가 떴다.
그래서 long long 형으로 변환해주는 stoll함수를 사용했더니 풀렸다. stoi -> int로, stol -> long으로, stoll -> long long으로 변환
문자열에서 숫자로 변환하고 숫자에서 문자열로 변환해주는 좋은 함수의 사용법을 알 수 있던 문제였던 것 같다.
*/
