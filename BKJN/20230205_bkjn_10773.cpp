#include <stdio.h>

int nums[100001];
int result[100001];

int main() {
  
    int num, cnt = 0;
    int sum = 0;
  
    scanf_s("%d", &num);
  
    for (int a = 0; a < num; a++) {
      scanf_s("%d", &nums[a]);
    }
  
    for (int a = 0; a < num; a++) {
 
      if (nums[a] != 0) {
            result[cnt] = nums[a];
            cnt++;
        }
      
        else if (nums[a] == 0) {
            result[cnt - 1] = 0;
            cnt--;
        }
    }
  
    for (int a = 0; a <= cnt; a++) {
        sum += result[a];
    }
  
    printf("%d\n", sum);
  
    return 0;
}
