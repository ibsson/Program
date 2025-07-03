#include <iostream>
using namespace std;

int main(void) {
    int c = 0, n = 0, m = 0;
    
    cin >> c >> n >> m;
    
    int ans = (c*n)-m;
    
    if (ans > 0) cout << ans << endl;
    else cout << "0" << endl;
    
    return 0;
}
