#include <iostream>
using namespace std;

int gcd(int a, int b) { // 최대 공약수
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { // 최소 공배수
    return (a * b) / gcd(a, b);
}
int main(void) {
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int M = 0, N = 0, x = 0, y = 0;
        int result = -1;

        cin >> M >> N >> x >> y;

        int maxi = lcm(M, N);

        for (int j = x; j <= maxi; j += M) {
            int ny = j % N;

            if (ny == 0) ny = N;

            if (ny == y) {
                result = j;
                break;
            }
        }

        cout << result << "\n";
    }
    return 0;
}

/*
이 문제는 계속 시간초과가 떠서 구글링을 해서 풀었다.
최소공배수와 나머지를 이용해서 풀면 쉽게 풀리는 문제였다.
이런 수학적인 문제를 푸는게 조금 어려운 것 같다.
직관적으로 보이지 않기 때문인 것 같다.
이런 정수론 문제를 많이 풀어보면서 푸는 방식을 알아가야겠다.
*/
