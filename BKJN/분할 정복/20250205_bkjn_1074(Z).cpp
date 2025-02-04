#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int ans = 0;
void dc(int y, int x, int size) {
    if (y == r && x == c) {
        cout << ans;
        return;
    }
    else if (r < y + size && r >= y && c < x + size && c >= x) {
        dc(y, x, size / 2);
        dc(y, x + size / 2, size / 2);
        dc(y + size / 2, x, size / 2);
        dc(y + size / 2, x + size / 2, size / 2);
    }
    else {
        ans += size * size;
    }
}
int main() {
    cin >> n >> r >> c;

    dc(0, 0, pow(2, n));

    return 0;
}
