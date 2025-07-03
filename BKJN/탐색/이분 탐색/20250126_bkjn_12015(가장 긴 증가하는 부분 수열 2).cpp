#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000005

int n;
int a[MAX];
int lis[MAX];

int binarysearch(int left, int right, int target) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;

        if (lis[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int j = 0;
    lis[0] = a[0];

    for (int i = 0; i < n; i++) {
        if (lis[j] < a[i]) {
            lis[j + 1] = a[i];
            j++;
        }
        else {
            int idx = binarysearch(0, j, a[i]);
            lis[idx] = a[i];
        }
    }

    cout << j + 1 << "\n";

    return 0;
}
