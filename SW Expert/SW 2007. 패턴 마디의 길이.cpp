#include <iostream>
#include <string.h>
using namespace std;
char str[31];
int main() {
	int t,tc, idx1=0, idx2 = 0,i;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> str;
		for (i = 1; i <= 10; i++) {
			idx1 = 0; idx2 = 0;
			while (idx1 <= 30 && str[idx2++ % i] == str[idx1++]) {}
			if (idx1 == 31) {
				cout << "#" << tc << " " << i << endl;
				break;
			}
		}
	}
}