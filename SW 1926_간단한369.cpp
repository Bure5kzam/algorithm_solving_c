#include <iostream>
using namespace std;
int itoa(int a) {
	int d=1, ans=0;
	while (a >= d) d *= 10;
	d /= 10;
	while (a) {
		if ((a / d) % 3 == 0 && a/d !=0) ans++;
		a %= d;
		d /= 10;

	}
	return ans;
}
int main() {
	int n, ret, j;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ret = itoa(i);
		if (!ret) cout << i << " ";
		else { for (j = 0; j < ret; j++) cout << '-'; cout << " "; }
	}
}