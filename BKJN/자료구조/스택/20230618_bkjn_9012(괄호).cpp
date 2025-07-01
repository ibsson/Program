#include <stdio.h>

char par[51];

int get_len(){
	
	int count = 0;
	
	for(int i = 0; i < 51; i++){
		if(par[i] == '\0') break;
		
		count++;
	}
	
	return count;
}

int main() {

	int T = 0;
	int cnt = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		
		cnt = 0;
		
		scanf("%s", par);
		
		for (int k = 0; k < get_len(); k++) {
			if(cnt < 0) break;
			
			if (par[k] == '(') {
				cnt++;
			}
			
			if (par[k] == ')') {
				cnt--;
			}
		}
		
		if (cnt == 0) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
