#include <iostream>
using namespace std;
/*
* N : �� ����
* ARR : �ܿ� �� ��
* S[n][s] :n��° ���� ���� s��°�� ���� ���� �ִ밪 (s: 1<->3)
*S[n][4] = S[n][1<->3]�� max;
*/
int N, ARR[10002], S[10002][4] = { 0, };

void f(int n) {
	int mx = 0;

	S[n][0] = S[n - 1][3];
	if (S[n][0] > mx) mx = S[n][0];

	S[n][1] = S[n - 1][0] + ARR[n];
	if (S[n][1] > mx) mx = S[n][1];

	S[n][2] = S[n - 1][1] + ARR[n];
	if (S[n][2] > mx) mx = S[n][2];

	S[n][3] = mx;

	if (n < N)f(n + 1);

}

int main() {
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++) cin >> ARR[i];
	
	//ù��° ������ ���� ��ġ
	S[1][1] = ARR[1];
	S[1][3] = S[1][1];
	f(2);
	cout << S[N][3] << endl;
	/*for (i = 0; i < 4; i++) {
		for (j = 1; j <= N; j++) {
			cout << S[j][i] << " ";
		}
		cout << endl;
	}*/
}