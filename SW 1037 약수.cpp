#include <iostream>
using namespace std;

int main() {
	int N, i;
	int tmp, mn = 1e9, mx = -1e9;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		if (mn > tmp) mn = tmp;
		if (mx < tmp) mx = tmp;
	}
	cout << mn * mx << endl;
}