#include <stdio.h>
#include <string.h>

char S[101] = { 0 };

int get_len(){
	
	int cnt = 0;
	
	for(int i = 0; i < 101; i++){
		if(S[i] == '\0') return cnt;
		
		cnt++;
	}
}

void ROT13(int len) {
	
    for (int i = 0; i < len; i++) {
		
        char tmp = S[i];
        
        if ((tmp >= 'A' && tmp <= 'Z') || (tmp >= 'a' && tmp <= 'z')) {
			
            char base = (tmp >= 'A' && tmp <= 'Z') ? 'A' : 'a';
			
            S[i] = (tmp - base + 13) % 26 + base;
        }
    }
}

int main(void){
	
	fgets(S, sizeof(S), stdin);
	
	int len = get_len();
	
	ROT13(len);
	
	printf("%s", S);
	
	return 0;
}
