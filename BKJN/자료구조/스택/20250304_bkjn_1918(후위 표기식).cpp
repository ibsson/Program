#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack <char> s;

int main(){
    cin >> str;
    
    int len = str.length();
    
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            cout << str[i];
            continue;
        }
        
        if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i] == '*' || str[i] == '/'){
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    
    return 0;
}