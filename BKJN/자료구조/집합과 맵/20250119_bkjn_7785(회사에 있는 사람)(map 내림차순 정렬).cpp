#include <iostream>
#include <map>
using namespace std;

int n;
string name, status;
map <string, int, greater<string>> _log;

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> status;

		if(!status.compare("enter")) _log[name]++;
		else if(!status.compare("leave")) _log[name]--;
	}

	for (auto it = _log.begin(); it != _log.end(); it++) {
		if(it->second != 0) cout << it->first << "\n";
	}

	return 0;
}
