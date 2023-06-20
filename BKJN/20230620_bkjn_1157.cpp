#include <stdio.h>

int word[1000001];
int cnt[26] = {0};

void quicksort(int L, int R) {

	int left = L;
	int right = R;
	int pivot = word[((L + R) / 2)];
	int room = 0;

	do {
		while (word[left] < pivot) left++;

		while (word[right] > pivot) right--;

		if (left <= right) {
			room = word[left];
			word[left] = word[right];
			word[right] = room;
			left++;
			right--;
		}

	} while (left <= right);

	if (L < right) quicksort(L, right);

	if (left < R) quicksort(left, R);

}

int get_len(){
	
	int count = 0;
	
	for(int i = 0; i < 1000001; i++){
		if(word[i] == '\0') break;
		
		count++;
	}
	
	return count;
}

int main() {
	
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //알파벳은 26개지만 널문자가 들어갈 공간으로 한칸 더 만들어줌(컴파일러마다 널문자 공간 유무로 오류가 뜰수도 안뜰수도 있음. 그냥 한칸 더 만들어 두는걸 습관화 하자)
	
	scanf("%ls", word);
	
	int len = get_len();
	
	for(int i = 0; i < len; i++){
		if(word[i] >= 'a' && word[i] <= 'z'){
			word[i] -= 32;
		}
	}
	
	quicksort(0, (len - 1));
	
	for(int i = 0; i < len; i++){
		for(int k = 0; k < 26; k++){
			if(word[i] == alphabet[k]){
				cnt[k]++;
				break;
			}
		}
	}
	
	int max = -1;
	int room = 0;
	int count = 0;
	
	for(int i = 0; i < 26; i++){
		if(max < cnt[i]){
			max = cnt[i];
			room = i;
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(max == cnt[i]){
			count++;
			if(count > 1){
				printf("?\n");
				return 0;
			}
		}
	}
	
	printf("%c\n", alphabet[room]);
	
	return 0;
}
