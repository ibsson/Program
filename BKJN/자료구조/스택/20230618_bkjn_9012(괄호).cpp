#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	cin.ignore();

	for (int t = 1; t <= T; t++) {
		stack <char> s;
		string str;
		cin >> str;

		bool chk = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') s.push(str[i]);
			else if (str[i] == ')') {
				if (s.empty()) {
					chk = false;
					break;
				}
				else {
					s.pop();
				}
			}
		}

		if (!s.empty() || !chk) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}

/*
#include <stdio.h>

char par[51];

int get_len(){
	
	int count = 0;
	
	for(int i = 0; i < 51; i++){
		if(par[i] == '\0') break;
		
		count++;
	}
	
	return count;
}

int main() {

	int T = 0;
	int cnt = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		
		cnt = 0;
		
		scanf("%s", par);
		
		for (int k = 0; k < get_len(); k++) {
			if(cnt < 0) break;
			
			if (par[k] == '(') {
				cnt++;
			}
			
			if (par[k] == ')') {
				cnt--;
			}
		}
		
		if (cnt == 0) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
*/
