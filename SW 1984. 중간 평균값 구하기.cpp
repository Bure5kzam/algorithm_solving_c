#include<iostream>
#include<math.h>
using namespace std;
int tmp, mx = 0, mn = 0, N, sum=0;
int main() {
	int i, j,t,tc;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		mx = 0; mn = 1e9; sum = 0;
		for (i = 0; i < 10; i++) {
			cin >> tmp;
			if (mx < tmp) mx = tmp;
			if (mn > tmp) mn = tmp;
			sum += tmp;
		}
		cout << "#" << tc << " " << round((double)(sum - mx - mn) / 8) << endl;
	}
}