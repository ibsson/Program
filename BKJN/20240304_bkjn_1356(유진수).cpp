#include <stdio.h>
#include <string.h>

int main() {
    char num[11];
    scanf("%s", num);

    int len = strlen(num);
    int result = 0;
    int flag = 0;

    if (len == 1) {
        printf("NO\n");
        return 0;
    }

    for (int i = 1; i < len; i++) {
        int left = 1, right = 1;

        for (int j = 0; j < i; j++) {
            left *= num[j] - '0';
        }

        for (int j = i; j < len; j++) {
            right *= num[j] - '0';
        }

        if (left == right) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
