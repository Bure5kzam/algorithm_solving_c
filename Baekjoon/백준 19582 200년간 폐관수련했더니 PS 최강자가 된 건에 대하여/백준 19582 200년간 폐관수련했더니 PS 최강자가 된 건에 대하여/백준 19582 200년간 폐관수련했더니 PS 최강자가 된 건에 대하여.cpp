#include <iostream>
using namespace std;
/*
* ARR : ��ȸ ���� ���� ������ ���� �Է¹޴� ����
* DP[0] : ���� ��ȸ ���� �̷�
* DP[1] : ���� ��ȸ ���� ���
*/
int N, ARR[111111][2] = { 0, };
long long int DP[2][2] = { 0, };
int main() {
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < 2; j++)cin >> ARR[i][j];
	}
	//cout << endl;
	for (i = 1; i <= N; i++) {
		int limit = ARR[i][0];
		int score = ARR[i][1];

		//1-1 ��ȸ�� �� ������ ���
		DP[1][0] = (DP[0][0] <= limit) ? DP[0][0] + score : 1e16;

		//2-1 ��ȸ�� �� �������� ���� ���

		long long int ret1 = 0, ret2 = 0;
		//2-2-1 ���� ��ȸ�� �� �����ϰ� �̹��� �������� �ʴ� ���
		ret1 = (DP[0][0]) ? DP[0][0]: 1e16;

		//2-2-2 �̹� ������ �ѹ� ��ȸ�� �������� ���� ���
		ret2 = (DP[0][1] <= limit) ? DP[0][1] + score : 1e16;
		DP[1][1] = (ret1 < ret2) ? ret1 : ret2;

		if (DP[1][0] == 1e16 && DP[1][1] == 1e16) {
			cout << "Zzz" << "\n";
			return 0;
		}

		DP[0][0] = DP[1][0];
		DP[0][1] = DP[1][1];
		cout << DP[0][0] << " " << DP[0][1] << " " << ret1 <<" " <<  ret2 <<  "\n";
	}
	cout << "Kkeo-eok" << "\n";
}