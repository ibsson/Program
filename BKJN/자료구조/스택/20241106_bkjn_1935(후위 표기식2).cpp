#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector <double> v;
stack <double> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string str;
	cin >> str;

	for (int i = 0; i < N; i++) {
		double tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+') {
			double num1 = s.top();
			s.pop();
			double num2 = s.top();
			s.pop();
			s.push(num2 + num1);
		}
		else if (str[i] == '-') {
			double num1 = s.top();
			s.pop();
			double num2 = s.top();
			s.pop();
			s.push(num2 - num1);
		}
		else if (str[i] == '*') {
			double num1 = s.top();
			s.pop();
			double num2 = s.top();
			s.pop();
			s.push(num2 * num1);
		}
		else if (str[i] == '/') {
			double num1 = s.top();
			s.pop();
			double num2 = s.top();
			s.pop();
			s.push(num2 / num1);
		}
		else {
			s.push(v[str[i] - 'A']);
		}
	}

	double res = s.top();
	s.pop();

	cout << fixed;
	cout.precision(2);
	cout << res << '\n';

	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    double Data;
};

class ArrStack {
public:
    int top;
    Node* Nodes;

    void Create_Node(int Size) {
        top = -1;
        Nodes = new Node[Size];
    }

    void Push(double data) {
        top++;
        Nodes[top].Data = data;
    }

    double Pop() {
        double tmp = Nodes[top].Data;
        top--;

        return tmp;
    }
};

int main(void) {
    int N = 0;
    cin >> N;

    string str;
    cin >> str;

    double* num = new double[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    ArrStack* Stack = new ArrStack;
    Stack->Create_Node(N);

    double sum = 0, tmp_1 = 0, tmp_2 = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            Stack->Push(num[str[i] - 'A']);
        }
        else {
            tmp_1 = Stack->Pop();
            tmp_2 = Stack->Pop();

            if (str[i] == '+') {
                sum = tmp_2 + tmp_1;
            }
            else if (str[i] == '-') {
                sum = tmp_2 - tmp_1;
            }
            else if (str[i] == '*') {
                sum = tmp_2 * tmp_1;
            }
            else if (str[i] == '/') {
                sum = tmp_2 / tmp_1;
            }
            Stack->Push(sum);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << Stack->Pop() << endl;

    delete[] num;
    delete[] Stack->Nodes;
    delete Stack;

    return 0;
}

/*
c++로 스택을 처음으로 구현 해보았다.
c++은 c언어와 유사하지만 약간 차이점이 있어서 헷갈렸다.
전에 후위표기식을 계산하는 문제를 구현해보아서 구현은 쉬웠다. 하지만 c++로 처음 스택을 구현해서 스택을 구현하는 부분에서 조금 시간이 걸렸다.
처음으로 class를 사용해서 푼 백준 문제다.
c++을 계속 사용해서 더욱 익숙해져야겠다.
*/
*/
