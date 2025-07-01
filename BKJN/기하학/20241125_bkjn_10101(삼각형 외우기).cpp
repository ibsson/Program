#include <iostream>
using namespace std;

int main(void){
    
    int a = 0, b = 0, c = 0;
    
    cin >> a;
    cin >> b;
    cin >> c;
    
    if(a == 60 && b == 60 && c == 60){
        cout << "Equilateral" << endl;
        return 0;
    }
    
    if((a + b + c) != 180) cout << "Error" << endl;
    else if((a == b) || (b == c) || (c == a)) cout << "Isosceles" << endl;
    else if((a != b) && (b != c) && (c != a)) cout << "Scalene" << endl;
    
    return 0;
}
