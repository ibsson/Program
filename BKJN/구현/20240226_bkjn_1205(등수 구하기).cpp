#include<stdio.h>

int main()
{
	int N = 0, myscore = 0, P = 0, rankcount = 0, myrank = 1;
	int scorelist[100] = { 0 };

	scanf("%d %d %d", &N, &myscore, &P);

	for (int i = 0; i < N; i++){
		scanf("%d", &scorelist[i]);
	}

	for (int i = 0; i < N; i++){
		if (myscore < scorelist[i]){
			myrank++;
		}
		else if (myscore == scorelist[i]){

		}
		else{
			break;
		}
		rankcount++;
	}

	if (rankcount == P){
		myrank = -1;
	}
	if (N == 0){
		myrank = 1;
	}

	printf("%d\n", myrank);
	return 0;
}
