#include <stdio.h>

int main() {
    int X = 0, stick = 64, tmp = 0, cnt = 1;

    scanf("%d", &X);

    while (1) {
        if (stick == X) break;
        else if (stick < X) {
            tmp = stick;
            while (1) {
                tmp /= 2;
                if (stick + tmp > X) continue;
                else {
                    stick += tmp;
                    cnt++;
                }

                if (stick == X) break;
            }
        }
        else stick /= 2;
    }

    printf("%d\n", cnt);

    return 0;
}

/*
이 문제는 처음에는 이해를 못했다가 읽다보니 이해가 됐다. 2진법으로 10진수를 만드는 코드라고 생각하고 만들었다.
앞으로 2진법으로 10진수를 만드는 코드를 짤때 이 코드를 활용하면 좋을 것 같다.
*/
