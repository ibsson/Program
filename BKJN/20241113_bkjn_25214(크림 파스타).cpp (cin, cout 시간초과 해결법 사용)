#include <iostream>
using namespace std;

int A[200001] = { 0 };

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;

	cin >> N;

	int dif_max = 0, A_max = -1, A_min = 1000000001;

	for (int i = 0; i < N; i++) {
		cin >> A[i];

		if (A_min > A[i]) A_min = A[i];

		if (dif_max < A[i]) {
			A_max = A[i];

			if (dif_max < A_max - A_min) dif_max = A_max - A_min;
		}

		cout << dif_max << " ";
	}

	cout << endl;

	return 0;
}

/*
계속 시간초과가 나서 방법을 찾아봤다.
찾아보니 cin, cout을 사용할때

	ios::sync_with_stdio(false);
	cin.tie(NULL);

이 문장을 추가해주면 속도 향상에 도움이 된다고 해서 사용했더니 풀렸다.
첫번째 줄은 C의 stdio와 C++의 iostream을 동기화 시켜주는 역할을 하는데 이걸 비활성화시켜줌으로써 C++만의 독립적인 버퍼를 생성해줘 사용하는 버퍼의 수가 줄어들게된 덕에 실행속도가 빨라지게 되는 원리이고,
두번째 줄은 cin과 cout의 묶음을 풀어줘서 버퍼를 비워주는 작업을 하지않게 되고 입출력이 그만큼 더 빨라지게 된다.
이런게 있다는 사실을 처음 알게 되었다.
앞으로 유용하게 쓸 수 있을 것 같다.
*/
