#include <iostream>
using namespace std;

int main(void){
    
    int N = 0;
    int a[5] = {0};
    
    cin >> N;
    
    for(int i = 0; i < 5 ; i++){
        cin >> a[i];   
    }
    
    int cnt = 0;
    
    for(int i = 0; i < 5; i++){
        if(N == a[i]) cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
