#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int N, M;
string str;
map <string, int> num;
vector <string> name;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> str;

		name.push_back(str);
		num.insert({ str, i });
	}

	for (int i = 0; i < M; i++) {
		cin >> str;

		if (str[0] >= 'A' && str[0] <= 'Z') {
			auto it = num.find(str);
			cout << it->second << "\n";
		}
		else {
			cout << name[stoi(str) - 1] << "\n";
		}
	}

	return 0;
}
