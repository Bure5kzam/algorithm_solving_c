#include <iostream>
#include <vector>
using namespace std;
/*
* N : ������ ����
* K : ������ ����
* DP[n][s] = n���� ���� s�� ����� ����� ��
*/
int N, K;
long long int DP[211][211] = { 0, };
//r : ����� ���� ����
//sum : r���� ���� ������� �� ���� ä������ ���� ��
long long int f(int r, int sum) {
	long long int ret = 0, num = 0;
	
	if (r == K) {
		if (sum == 0) return 1;
		else return 0;
	}

	int i, j;
	for (i = 0; i <= sum; i++) {
		//�湮�� ���� ���� ���
		if (DP[r + 1][sum - i] == -1) {
			num += (f(r + 1, sum - i) % (long long int)1e9);
		}
		//�湮 �ߴ� ���
		else num += (DP[r + 1][sum - i] % (long long int)1e9);
	}
	//Ž�� ����� ����
	DP[r][sum] = num;
	return num;
}
int main() {
	cin >> N >> K;
	int i, j;
	for (i = 0; i <= 200; i++) {
		for (j = 0; j <= 200; j++) {
			DP[i][j] = -1;
		}
	}
	cout << f(0, N) % (long long int)1e9 << endl;
	return 0;
}