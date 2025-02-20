#include <iostream>
using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001];

int main(){
    cin.tie(NULL); 
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        dp[i][i] = true;
    }
    
    for(int i = 0; i <= (N - 2); i++){
        if(arr[i] == arr[i + 1]) dp[i][i + 1] = true;
    }
    
    for(int i = N - 2; i >= 0; i--){
        for(int j = (i + 1); j <= (N - 1); j++){
            if(arr[i] == arr[j] && dp[i + 1][j - 1] == true) dp[i][j] = true;
        }
    }
    
    cin >> M;
    
    int S = 0, E = 0;
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        cout << dp[S-1][E-1] << "\n";
    }
    
    return 0;
}

/*
앞으로 dp문제를 풀땐 표를 적극적으로 활용해서 규칙을 찾아야겠다.
표를 만들면 규칙을 좀 더 쉽게 찾을 수 있는 것 같다
*/