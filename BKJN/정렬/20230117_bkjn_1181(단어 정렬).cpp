#include <stdio.h>

#define SWAP(a, b) ((a) ^= (b) ^= (a) ^= (b))

char word[20000][51];

int main() {
	
	int N = 0;
	int cnt[51] = { 0 };

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%s", word[i], 51);
		for (int k = 0; k < 51; k++) {
			if (word[i][k] != NULL) cnt[i]++;
			else if (word[i][k] == NULL) break;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = i; k < N; k++) {
			if (cnt[i] > cnt[k]) {
				for (int j = 0; j < 51; j++) {
					SWAP(word[i][j], word[k][j]);
					SWAP(cnt[i], cnt[k]);
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = i; k < N; k++) {
			if (cnt[i] == cnt[k]) {
				for (int j = 0; j < 51; j++) {
					if (word[i][j] > word[k][j]) {
						for (int h = 0; h < 51; h++) {
							SWAP(word[i][h], word[k][h]);
						}
						break;
					}
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {

		printf("%s\n", word[i]);
	}

	return 0;
}
