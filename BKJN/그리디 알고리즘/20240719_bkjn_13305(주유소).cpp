#include <stdio.h>
#include <stdlib.h>

long long int Get_Low_Price(long long int len[], long long int price[], int N) {

	long long int price_sum = 0;
	int current_index = 0;

	price_sum = price[0] * len[0];

	for (int i = 1; i < (N - 1); i++) {
		if (price[current_index] < price[i]) {
			price_sum += price[current_index] * len[i];
		}
		else {
			current_index = i;
			price_sum += price[current_index] * len[i];
		}
	}
	
	return price_sum;
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	long long int* len = (long long int*)malloc(sizeof(long long int) * (N - 1));
	long long int* price = (long long int*)malloc(sizeof(long long int) * N);

	for (int i = 0; i < (N - 1); i++) {
		scanf("%lld", &len[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%lld", &price[i]);
	}

	printf("%lld\n", Get_Low_Price(len, price, N));

	free(len);
	free(price);

	return 0;
}

/*
이 문제는 자료형 때문에 애먹었다.
우선 접근 방식은

1. 도시를 하나씩 이동하면서 이전 최소 가격보다 더 적은 가격이 나오면 그 가격으로 다음 도시로 이동한다

이렇게 풀었다. 코드는 잘 만들었는데 계속 58점이 나와서 당황했다.
그렇게 코드를 고쳐보다가 가격과 거리의 최대가 1,000,000,000이어서 int로 충분할 줄 알았기 때문에
계속 간과하고 있다가 한번 long long int로 바꾸었는데 그제서야 100점이 나왔다.
크기가 충분한 것 같아도 그것보다 좀 더 넉넉하게 크기를 잡는게 좋을 것 같다.
크기 넉넉하게 잡기, 그리디 문제를 푸는 방법 등 배워가는게 많은 문제였던 것 같다.
*/
