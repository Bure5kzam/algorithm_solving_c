#include <iostream>
using namespace std;
char arr[5][15];
int main() {
	int t, tc, i, j;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		for (i = 0; i < 5; i++) for (j = 0; j < 15; j++) { arr[i][j] = '_'; }
		for (i = 0; i < 5; i++) cin >> arr[i];
		cout << "#" << tc << " ";
		for (i = 0; i < 15; i++) { for (j = 0; j < 5; j++) if (arr[j][i] != '_') cout << arr[j][i]; }
		cout << endl;
	}
}