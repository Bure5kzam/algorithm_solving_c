#include  <iostream>
using namespace std;
long long int A, B;
int f(int cnt, int n) {
	
	int ret = -1, ans =1e9;

	if (n == A) return cnt;
	else if (n <A) return 1e9;

	if (n % 2 == 0) {
		ret = f(cnt + 1, n / 2);
		if (ans > ret) ans = ret;
	}

	if (n % 10 == 1) {
		ret = f(cnt + 1, n / 10);
		if (ans > ret) ans = ret;
	}
	

	return ans;
}
int main() {	int t, tc, ret=0;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> A >> B;
		ret = f(1, B);
		if(ret != 1e9)	cout << "#" << tc << " " << ret  << endl;
		else cout << "#" << tc << " " << -1  << endl;
	}
}