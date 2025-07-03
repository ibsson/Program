#include <stdio.h>

struct point {
	int cx;
	int cy;
	int r;
};

int get(int x, int y, int cx, int cy, int r) {

	if (((x - cx) * (x - cx) + (y - cy) * (y - cy)) < (r * r)) return 1;
	else return 0;

}

int main() {

	struct point num[50];
	int T = 0;
	int x1 = 0; int y1 = 0; 
	int x2 = 0; int y2 = 0;
	int n = 0;
	int check1 = 0; int check2 = 0;
	int cnt = 0;

	scanf_s("%d", &T);

	while (1) {
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2); //출발, 도착점
		scanf_s("%d", &n); //행성계의 갯수

		for (int i = 0; i < n; i++) {
			scanf_s("%d %d %d", &num[i].cx, &num[i].cy, &num[i].r);
			check1 = get(x1, y1, num[i].cx, num[i].cy, num[i].r);
			check2 = get(x2, y2, num[i].cx, num[i].cy, num[i].r);
			if (check1 != check2) cnt++;
		}

		printf("%d\n", cnt);

		cnt = 0;
		T--;

		if (T == 0) break;
	}

	return 0;
}
