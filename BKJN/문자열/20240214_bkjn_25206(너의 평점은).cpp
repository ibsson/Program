#include <stdio.h>
#include <string.h>

typedef struct subject {

	char name[51];
	double score = 0;
	char grade[3];

}Subject;

int main(void) {

	Subject a[20];
	double b = 0;
	double c = 0;
	
	for (int i = 0; i < 20; i++) {
		scanf("%s", a[i].name, 51);
		scanf("%lf", &a[i].score);
		scanf("%s", a[i].grade, 3);

		if (strcmp("P", a[i].grade) == 0) continue;
		else if (strcmp("F", a[i].grade) == 0) {
			b += a[i].score * 0.0;
			c += a[i].score;
		}
		else if (strcmp("A+", a[i].grade) == 0) {
			b += a[i].score * 4.5;
			c += a[i].score;
		}
		else if (strcmp("A0", a[i].grade) == 0) {
			b += a[i].score * 4.0;
			c += a[i].score;
		}
		else if (strcmp("B+", a[i].grade) == 0) {
			b += a[i].score * 3.5;
			c += a[i].score;
		}
		else if (strcmp("B0", a[i].grade) == 0) {
			b += a[i].score * 3.0;
			c += a[i].score;
		}
		else if (strcmp("C+", a[i].grade) == 0) {
			b += a[i].score * 2.5;
			c += a[i].score;
		}
		else if (strcmp("C0", a[i].grade) == 0) {
			b += a[i].score * 2.0;
			c += a[i].score;
		}
		else if (strcmp("D+", a[i].grade) == 0) {
			b += a[i].score * 1.5;
			c += a[i].score;
		}
		else if (strcmp("D0", a[i].grade) == 0) {
			b += a[i].score * 1.0;
			c += a[i].score;
		}
	}

	printf("%lf\n", b / c);

	return 0;
}
