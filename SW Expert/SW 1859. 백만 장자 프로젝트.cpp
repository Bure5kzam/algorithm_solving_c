#include <iostream>
using namespace std;
int arr[1000001] = {0, }, mx = 0, N,i,t,tc;
long long int sum;
int main() {
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> N;
		for (i = 0; i < N; i++) cin >> arr[i];
		for (i = N - 1; i >= 0; i--) {
			if (mx < arr[i]) mx = arr[i];
			sum += (long long int)(mx - arr[i]);
		}
		cout <<"#" << tc << " " <<  sum << endl;
		sum = 0, mx = 0;
	}
}

/*
3
3
10 7 6
3
3 5 9
5
1 1 3 1 2
*/