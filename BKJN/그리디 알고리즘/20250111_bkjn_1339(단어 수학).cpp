#include <iostream>
#include <algorithm>

using namespace std;

string arr[10];
int len[10];
int alpha[26];

bool Compare(int a, int b) { return a > b; }

int main(void) {
    int N;
    int cal;
    int result = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        len[i] = arr[i].length();
    }

    for (int i = 0; i < N; i++) {
        cal = 1;

        for (int j = len[i] - 1; j >= 0; j--) {
            alpha[arr[i][j] - 'A'] += cal;
            cal *= 10;
        }
    }

    sort(alpha, alpha + 26, Compare);

    for (int i = 0; i < 10; i++) {
        result += alpha[i] * (9 - i);
    }

    cout << result << "\n";
}

/*
그리디로 풀리는 문제였다.
처음엔 각각의 단어에 전부 숫자를 넣어서 계산하려고 했다. 하지만 잘 안돼서 다른방법을 생각해봤지만 모르겠어서 검색을 해서 풀었다.

각각의 단어에 대해서 생각할 것이 아니라, 모든 단어들에 알파벳이 어느 위치에 등장하고 그것이 10의 몇 제곱을 나타내는 지를 모두 더해준다. 그런 뒤 그를 내림차순 정렬해서 큰 값부터 9, 8, 7,.. 이렇게 넣어주면 된다.
이 방법으로 푸니 굉장히 쉽게 풀렸다. 앞으로 문제를 풀때 브루트포스, 그리디 등 다양한 방법을 염두에 두며 시야를 넓히고 문제를 푸는 습관을 들여야겠다.
*/
