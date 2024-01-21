#include <stdio.h>
#include <string.h>

int main() {
	
	int T = 0;
	int p = 0;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		
		char word[1001];
		
		scanf("%s", word);
		
		p = strlen(word);
		
		printf("%c%c\n", word[0], word[p-1]);
		
	}
	return 0;
}
