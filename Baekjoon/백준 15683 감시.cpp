#include <iostream>
using namespace std;

/*
* D1[d][c] = ���⿡ ���� y,x ��Ÿ�� 
* D2[m][n] ��m�� ���� �� �ִ� ���� ��.
*
*/

int M, N, FIELD[10][10] = { 0, }, CAM_COORDS[10][3] = { 0, }, NUM = 1;
int D[4][2] = { { -1,0 }, {0,1},{1,0},{0,-1} };
int D2[6][5] = { {0},
	{1,0},
	{2, 0,2},
	{2, 0,1},
	{3, 0, 1, 2},
	{4,0,1,2,3}
};

//s��° ī�޶� Ž��(ī�޶� �ε���, s-1��° ī�޶��� Ž���� �ݿ��� �� �迭, s-1��° ī�޶� Ž���� �ݿ��� �þ� ��
int f(int s, int arr[][10], int value) {
	/*
	* c* : ���� ��
	* n* : ���� ������ ��
	* y, x : ��ǥ
	* m : ī�޶� ��
	* cField : s��° ī�޶��� �þ� Ž���� �ݿ��� �迭
	* buf[d][n] : s��° ī�޶� d�������� n��° Ž������ �� �þ߰��� �ݿ��Ǿ��°�?
	*/

	int ret, mx = 1e9;
	int i, j, d, d2;
	int buf[4][11] = { 0, };
	if (s == NUM) return value;

	//f�� s��° ī�޶��� ���� ����� ����� field
	int cField[10][10] = { 0, };
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) cField[i][j] = arr[i][j];

	int cy = CAM_COORDS[s][0], cx = CAM_COORDS[s][1]; // ���� ī�޶��� ��ǥ
	int cm = CAM_COORDS[s][2]; // //���� ī�޶��� ��
	int ny = cy, nx = cx; //Ž���� ���� ���� ����

	int cv = value;
	for (d = 0; d < 4; d++) {
		cv = value;

		//�𵨺� ���� ����
		for (d2 = 1; d2 <= D2[cm][0]; d2++) {
			ny = cy; nx = cx;
			int cd2 = (d + D2[cm][d2]) % 4;
			buf[cd2][0] = 0;//[x][y] = x�������� �����Ҷ� y��°�� �þ߷� �ƴ°�?
			//�� �� �ι��� ���� ����
			while (1) {
				ny += D[cd2][0]; nx += D[cd2][1];
				if (1 > ny || ny > M || 1 > nx || nx > N)break;
				if (cField[ny][nx] == 6) break;

				//������̾����� ����صΰ� ��ȯ
				if (cField[ny][nx] == 0) {
					buf[cd2][++buf[cd2][0]] = 1;
					cField[ny][nx] = -1;
					cv--;
				}
				else {
					buf[cd2][++buf[cd2][0]] = 0;
				}
				//�ƴϾ����� ��Ͼ���.
			}

		}
		for (int p1 = 1; p1 <= M; p1++) {
			for (int p2 = 1; p2 <= N; p2++) {
				cout << cField[p1][p2] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// ȣ��
		ret = f(s + 1, cField, cv);
		if (mx > ret) mx = ret;

		//�𵨺� ���� ���� ���
		for (d2 = 1; d2 <= D2[cm][0]; d2++) {
			ny = cy; nx = cx;
			int cd2 = (d + D2[cm][d2]) % 4;

			//�� �� �ι��� ���� ���� ���
			for (int idx = 1; idx <= buf[cd2][0]; idx++) {
				ny += D[cd2][0]; nx += D[cd2][1];
				//������̾����� ����صΰ� ��ȯ
				if (buf[cd2][idx])cField[ny][nx] = 0;
				//�ƴϾ����� ��Ͼ���.
			}
		}
	return mx;
}
int main() {
	int i, j, value = 0;
	freopen("input.txt", "r", stdin);
	cin >> M >> N;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++, value++) {
			cin >> ARR[i][j];
			if (ARR[i][j] == 6) value--;
			if (ARR[i][j] != 0 && ARR[i][j] != 6) {
				CAM_COORDS[NUM][0] = i;
				CAM_COORDS[NUM][1] = j;
				CAM_COORDS[NUM][2] = ARR[i][j];
				NUM++;
				value--;
			}
		}
	}

	cout << f(1, ARR, value) << endl;
}