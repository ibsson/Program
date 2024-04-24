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
