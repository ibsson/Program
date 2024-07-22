#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int Compare(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 < *elem2) return 1;
	else if (*elem1 > *elem2) return -1;
	else return 0;
}

int main(void) {

	int triangle[3];

	while (1) {
		scanf("%d %d %d", &triangle[0], &triangle[1], &triangle[2]);

		if (triangle[0] == 0 && triangle[1] == 0 && triangle[2] == 0) break;

		qsort(triangle, 3, sizeof(int), Compare);

		if (triangle[0] * triangle[0] == (triangle[1] * triangle[1]) + (triangle[2] * triangle[2])) {
			printf("right\n");
		}
		else printf("wrong\n");
	}

	return 0;
}
