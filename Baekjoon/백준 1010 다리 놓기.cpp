#include <iostream>
using namespace std;
int a, b, mem[31][31] = { 0, }, cnt=0;

int d(int n, int r) {
	
	int i, j, ret = 0, sum=0;
	cnt++;
	if (n == a+1 || a-n == b-r) return 1;
	if (a - n > b - r) return 0;
	
	for (i = r; i<= b; i++) {

		if (mem[n+1][i+1] == 0) {
			ret = d(n + 1, i + 1);
			mem[n+1][i+1] = ret;
		}
		else ret = mem[n+1][i+1];
		sum += ret;
	}
	return sum;
}

int main() {
	int N, i, j, k;
	
	cin >> N;
	for (i = 1; i <= N; i++) {
		cnt = 0;
		cin >> a >> b;
		
		//cout << cnt << " : " << d(1, 1) << endl;
		cout  << d(1, 1) << endl;
		for (j = 1; j < 31; j++) for (k = 1; k < 31; k++) mem[j][k] = 0;
	}
}