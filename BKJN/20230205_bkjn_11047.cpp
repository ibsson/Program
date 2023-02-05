#include <stdio.h>

int coin[10];

int main() {
  
    int n, k;
    int cnt = 0;
  
    scanf_s("%d %d", &n, &k);
  
    for (int a = 0; a < n; a++) {
        scanf_s("%d", &coin[a]);
    }
  
    int a = n - 1;
  
    while (k > 0) {
      
        if (coin[a] > k) a--;
      
        else {
            k -= coin[a]; 
            cnt++;
        }
    }
  
    printf("%d", cnt);
  
  return 0;
}
