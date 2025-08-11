#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cnt = 0;
	string str;

	while (true)
	{
		cnt = 0;
		getline(cin, str);

		if (str[0] == '#')
			break;

		for (int ii = 0; ii < str.length(); ii++)
		{
			if (str[ii] == 'a' || str[ii] == 'e' || str[ii] == 'i' || str[ii] == 'o' || str[ii] == 'u'
				|| str[ii] == 'A' || str[ii] == 'E' || str[ii] == 'I' || str[ii] == 'O' || str[ii] == 'U')
				cnt++;
		}

		cout << cnt << endl;

	}
}
