#include <stdio.h>
#include <string.h>

int is_palindrome(char* word, int start, int end) {

    while (start < end) {
        if (word[start] != word[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main(void) {

    char word[101] = { 0 };

    scanf("%s", word, 101);

    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        if (is_palindrome(word, i, len - 1) == 1) {
            printf("%d\n", len + i);
            return 0;
        }
    }

    return 0;
}

/*
이 문제는 이렇게 접근했다.

1. 맨 앞과 맨 뒤에서 시작해서 같은 부분이 나오고 끝 index까지 같다면 맨 앞에서 처음 같은 부분이 나온 곳 까지의 길이와 len을 더해준다.

이렇게 풀었다. 이것도 계속 풀어보다가 잘 안풀려서 다른사람의 코드를 참고했다.
이정도 난이도는 살짝 어렵다. 하지만 이런 문제를 계속 풀어야 실력이 는다고 생각한다.
계속해서 내가 어렵다고 느끼는 문제를 풀어봐야겠다.
*/
