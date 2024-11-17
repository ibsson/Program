#include <iostream>
#include <math.h>
using namespace std;

int main(void) {

	double XA = 0, YA = 0, XB = 0, YB = 0, XC = 0, YC = 0;
	double max = -1, min = 10000000;

	cin >> XA >> YA >> XB >> YB >> XC >> YC;

	if ((XA == XB && XA == XC) || (YA - YB) / (XA - XB) == (YA - YC) / (XA - XC)) {
		cout << "-1.0\n";
		return 0;
	}

	double len[3];

	len[0] = sqrt((XA - XB) * (XA - XB) + (YA - YB) * (YA - YB)) + sqrt((XA - XC) * (XA - XC) + (YA - YC) * (YA - YC));
	len[1] = sqrt((XB - XA) * (XB - XA) + (YB - YA) * (YB - YA)) + sqrt((XB - XC) * (XB - XC) + (YB - YC) * (YB - YC));
	len[2] = sqrt((XC - XA) * (XC - XA) + (YC - YA) * (YC - YA)) + sqrt((XC - XB) * (XC - XB) + (YC - YB) * (YC - YB));

	for (int i = 0; i < 3; i++) {
		if (max < len[i]) max = len[i];
		if (min > len[i]) min = len[i];
	}

	printf("%.16f", 2 * (max - min));

	return 0;
}
