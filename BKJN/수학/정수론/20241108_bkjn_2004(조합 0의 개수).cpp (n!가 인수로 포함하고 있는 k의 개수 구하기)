#include <iostream>
using namespace std;

long long int cnt_k(int, int);

int main(void) {

	int n = 0, m = 0;

	cin >> n >> m;

	long long int cnt_2 = cnt_k(n, 2) - (cnt_k(m, 2) + cnt_k((n - m), 2));
	long long int cnt_5 = cnt_k(n, 5) - (cnt_k(m, 5) + cnt_k((n - m), 5));

	if (cnt_2 > cnt_5) cout << cnt_5 << endl;
	else cout << cnt_2 << endl;

	return 0;
}

long long int cnt_k(int N, int k) {

	long long int cnt = 0;
	long long int tmp = k;

	while (tmp <= N) {
		cnt += N / tmp;

		tmp *= k;
	}

	return cnt;
}

/*
조합 공식에서 10이 나오는 횟수만 구하면 된다고 생각해서 2와 5의 개수를 구했는데 계속 시간초과가 나서
여러 방법을 생각해봤지만 떠오르지 않았다. 결국 검색을 했다.
n!가 인수로 포함하고 있는 k의 개수 구하는 방법을 찾아서 사용을 했다.
n!에 인수로 포함된 k의 개수는,

"n 이하의 범위에서 k 
1
 , k 
2
 , k 
3
  ... 의 배수를 모두 카운트하여 더하는 것" 으로 구할 수 있다.
이 방법을 사용해서 풀었더니 맞았다.
내 스스로 풀어내지는 못했지만 답을 구하기 위한 조건을 스스로 알아냈다는 점은 긍정적이라고 생각한다.
앞으로는 어려운 문제에서 조건도 스스로 알아내고, 그 문제도 끝까지 스스로 풀어내기 위해 더 노력해야겠다.
*/
