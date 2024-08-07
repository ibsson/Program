#include <stdio.h>
#include <string.h>

int main(void) {

	char jae[1000] = { 0 };
	char hospital[1000] = { 0 };

	scanf("%s", jae, 1000);
	scanf("%s", hospital, 1000);

	int len_jae = strlen(jae);
	int len_hospital = strlen(hospital);

	if (len_jae >= len_hospital) printf("go\n");
	else printf("no\n");

	return 0;
}
