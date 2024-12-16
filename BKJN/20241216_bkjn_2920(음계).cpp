#include <iostream>
using namespace std;

int main(void) {
    int num[8], judge[8] = {0};
    
    for (int i = 0; i < 8; i++) {
        cin >> num[i];
        if (i != 0) {
            if (num[i - 1] < num[i]) judge[i] = 1;  //ascending
            if (num[i - 1] > num[i]) judge[i] = 0;  //descending
        }
    }
    for (int i = 2; i < 8; i++) {
        if (judge[i - 1] != judge[i]) {
            cout << "mixed";
            return 0;
        }
    }
    
    if (judge[1]) cout << "ascending";
    else cout << "descending";
    
    return 0;
}
