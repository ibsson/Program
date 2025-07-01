#include <stdio.h>

int main(){
  int N = 0;
  int cnt = 0;
  int z = 0;
  char arr[101];
  
  scanf_s("%d", &N);
  
  for(int i = 0; i < N; i++){
    scanf_s("%s", arr, 101); 
    
    for(int d = 0; arr[d] != '\0'; d++){
      cnt = 0;
      for(int f = d + 1; arr[f] != '\0'; f++){
        if((arr[d] == arr[f]) && (cnt == 1)){
          cnt = 2;
          break;
        }
        if(arr[d] != arr[f]){
          cnt = 1;
        }
      }
      if(cnt == 2){
        break;
      }
    }
    if(cnt != 2){
      z += 1;
    }
  }
  
  printf("%d\n", z);
  
  return 0;
}
