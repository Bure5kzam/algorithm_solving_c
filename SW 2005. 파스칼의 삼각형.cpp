#include <iostream>
using namespace std;
int arr[11][2] = { 0, };
int main() {
	int N, i, j, t,tc;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> N;
		cout << "#" << tc << endl;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= i; j++) {
				if (j == 1) arr[j][i % 2] = 1;
				else arr[j][i % 2] = arr[j - 1][(i + 1) % 2] + arr[j][(i + 1) % 2];
			}
			for (j = 1; j <= i; j++) cout << arr[j][i % 2] << " ";
			cout << endl;
		}
		for (i = 1; i < 10; i++) for(j=0;j<=1;j++)arr[i][j] = 0;
	}
}