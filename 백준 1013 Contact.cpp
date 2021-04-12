#include <iostream>
#include <string>
using namespace std;
int N;
string s;
int fun(int n);
int pls(int &st, char c, int status) {
	int ret = 0, ans = 0;
	st--;
	for (; s[st] == c; st++) {
		if (status) {
			ret = fun(st+1);
			if (ret) ans = 1;
		}
	}
	return ans;
}

int fun(int n) {
	if (n == s.length()) return 1;
	string ptrn[2] = { "100+1+", "01" };
	int pn = 0, ret=0;

	for (pn = 0; pn < 2; pn++) {
		int si = n, ch = 0;
		//패턴길이 기준으로 비교
		for(int pi = 0 ; pi < ptrn[pn].length(); pi++) 
		{
			//패턴이 +일때
			if (ptrn[pn][pi] == '+') {
				ret = pls(si, s[si - 1], (ptrn[pn].length() - 1 == pi) ? 1 : 0);
				if (ret) ch = 1;
			}
			else {
				if (ptrn[pn][pi] == s[si]) {
					si++; 
					if (pi + 1 == ptrn[pn].length()) ret = fun(si);
					if (ret) ch = 1;
				}
				else {
					break; 
				}
			}
		}
		if (ch) return ch;
	}
	return 0;
}
int main() {
	int i, j, tc, t, ret;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> s;
		ret = fun(0);
		cout << ((ret) ? "YES" : "NO") << endl;
	}
}