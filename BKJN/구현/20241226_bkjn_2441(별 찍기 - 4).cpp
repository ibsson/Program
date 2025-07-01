#include <iostream>

using namespace std;

int main(void) {
    int count = 0;
    cin >> count;

    for (int i = 0; i < count; i++) {
        for(int j = 1;j <= i;j++) {
            cout << " ";
        }
        for (int j = 1 ; j <= count-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
