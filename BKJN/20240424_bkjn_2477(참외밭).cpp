#include <stdio.h>

typedef struct position {
	int x;
	int y;
}Position;

Position Location[6];

Position Get_Max() {

	Position max;
	max.x = -600, max.y = -600;

	for (int i = 0; i < 6; i++) {
		if (max.x < Location[i].x) max.x = Location[i].x;
		if (max.y < Location[i].y) max.y = Location[i].y;
	}

	return max;
}

Position Get_Min() {

	Position min;
	min.x = 600, min.y = 600;

	for (int i = 0; i < 6; i++) {
		if (min.x > Location[i].x) min.x = Location[i].x;
		if (min.y > Location[i].y) min.y = Location[i].y;
	}

	return min;
}

Position Get_Mid(Position max, Position min) {

	Position mid;

	for (int i = 0; i < 6; i++) {
		if (Location[i].x > min.x && Location[i].x < max.x) mid.x = Location[i].x;
		if (Location[i].y > min.y && Location[i].y < max.y) mid.y = Location[i].y;
	}

	return mid;
}

int Get_Small_Square_Size(Position max, Position min, Position mid) {

	int small_x = 0, small_y = 0;

	for (int i = 0; i < 6; i++) {
		if (mid.x == Location[i].x && mid.y != Location[i].y) {
			small_y = Location[i].y;
			break;
		}
	}

	for (int i = 0; i < 6; i++) {
		if (mid.y == Location[i].y && mid.x != Location[i].x) {
			small_x = Location[i].x;
			break;
		}
	}

	if (small_x > mid.x) small_x -= mid.x;
	else small_x = mid.x - small_x;

	if (small_y > mid.y) small_y -= mid.y;
	else small_y = mid.y - small_y;

	int small = small_x * small_y;

	return small;
}

int main(void) {

	int K = 0, A = 0, B = 0;

	scanf("%d", &K);

	for (int i = 0; i < 7; i++) {
		scanf("%d %d", &A, &B);
		if (A == 1) {
			Location[i].x += B;
			if (Location[i].x == 0 && Location[i].y == 0) break;
			Location[i + 1] = Location[i];
		}
		else if (A == 2) {
			Location[i].x -= B;
			if (Location[i].x == 0 && Location[i].y == 0) break;
			Location[i + 1] = Location[i];
		}
		else if (A == 3) {
			Location[i].y -= B;
			if (Location[i].x == 0 && Location[i].y == 0) break;
			Location[i + 1] = Location[i];
		}
		else if (A == 4) {
			Location[i].y += B;
			if (Location[i].x == 0 && Location[i].y == 0) break;
			Location[i + 1] = Location[i];
		}
	}

	Position max = Get_Max();
	Position min = Get_Min();

	int big = (max.x - min.x) * (max.y - min.y);

	Position mid = Get_Mid(max, min);

	int small = Get_Small_Square_Size(max, min, mid);

	printf("%d\n", K * (big - small));

	return 0;
}

/*
#접근 방법
좌표를 이용해 푼다.
큰 사각형 - 작은 사각형
작은 사각형은 최대 좌표 최소 좌표 사이 점을 구해서 구한다

로 접근을 해서 풀었다. 쉽지 않았다. 하지만 느낀 것이 많다. 도형문제는 좌표를 이용해서 푸는것이 편하다는 것을 느꼈고, 코드를 본격적으로 짜기 전에 문제를 
일반화 하는것이 코딩할때 굉장히 중요하다는 것을 느꼈고, 또 일반화 하는 것이 가장 어렵다는 것과, 일반화만 된다면 코드는 금방 짠다는 것을 느꼈다.
앞으로 도형 문제 풀때는 좌표를 이용해서 풀면 좋을 것 같고, 문제를 일반화를 하는 연습을 많이 해봐야 겠다.
*/
