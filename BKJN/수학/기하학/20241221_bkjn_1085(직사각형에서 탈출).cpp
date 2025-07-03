#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int x = 0, y = 0, w = 0, h = 0;
    int tmp1 = 0, tmp2 = 0;
  
    cin >> x >> y >> w >> h;
    tmp1 = min(x,y);
    tmp2 = min(w-x,h-y);
    cout << min(tmp1,tmp2);

    return 0;
}
