#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	int dp[11] = { 0 };

	cin >> N;
	dp[1] = 0, dp[2] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + (i - 1);
	}

	cout << dp[N] << endl;

	return 0;
}

/*
더 좋은 방법이 있어서 만들었다.
확실히 규칙을 알아내고 점화식을 만들어내니 굉장히 쉽게 풀린다.
점화식을 만드는 연습을 정말 많이 해봐야겠다.
*/

/*
#include <iostream>
using namespace std;

int sum = 0;

int Get_Result(int);

int main(void) {

	int N = 0;

	cin >> N;

	Get_Result(N);

	cout << sum << endl;

	return 0;
}

int Get_Result(int num) {

	if (num == 1) return 1;

	int tmp_1 = 0, tmp_2 = 0;

	if (num % 2 == 0) {
		tmp_1 = Get_Result(num / 2);
		tmp_2 = Get_Result(num / 2);
		sum += (tmp_1 * tmp_2);
	}
	else {
		tmp_1 = Get_Result(num / 2);
		tmp_2 = Get_Result((num / 2) + 1);
		sum += (tmp_1 * tmp_2);
	}

	return tmp_1 + tmp_2;
}
*/

/*
이 문제는 dp로 풀었다. 문제를 보고 top-down 풀이방식이 생각이 나서 재귀함수로 풀어내었다.
dp문제는 문제를 보고 점화식을 이끌어내는게 가장 중요하다고 생각했다.
하지만 문제를 푸는 방법 자체는 쉽게 알아냈지만 역시 재귀함수를 구현해내는것은 약간 어려웠다.
하지만 계속 손으로 써가면서 점화식을 만들었고, 재귀함수를 완성해서 풀어냈다.
내 스스로 풀어낸 재귀함수 문제라서 뿌듯하다. dp로 푸는 문제가 많은 것으로 알고있다.
그렇기 때문에 dp문제들을 많이 풀어보고 점화식을 만들어내는 연습을 정말 많이 해야겠고, top-down 방식과 bottom-up 방식 모두 다 많이 풀어봐야겠다.
*/
