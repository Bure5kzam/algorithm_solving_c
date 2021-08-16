#include <iostream>
using namespace std;

/*
* D1[d][c] = 방향에 따른 y,x 델타값 
* D2[m][n] 모델m이 가질 수 있는 방향 값.
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

//s번째 카메라를 탐색(카메라 인덱스, s-1번째 카메라의 탐색이 반영된 맵 배열, s-1번째 카메라 탐색이 반영된 시야 값
int f(int s, int arr[][10], int value) {
	/*
	* c* : 현재 값
	* n* : 다음 연산할 값
	* y, x : 좌표
	* m : 카메라 모델
	* cField : s번째 카메라의 시야 탐색이 반영된 배열
	* buf[d][n] : s번째 카메라가 d방향으로 n번째 탐색했을 때 시야값이 반영되었는가?
	*/

	int ret, mx = 1e9;
	int i, j, d, d2;
	int buf[4][11] = { 0, };
	if (s == NUM) return value;

	//f의 s번째 카메라의 방향 계산이 적용된 field
	int cField[10][10] = { 0, };
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) cField[i][j] = arr[i][j];

	int cy = CAM_COORDS[s][0], cx = CAM_COORDS[s][1]; // 현재 카메라의 좌표
	int cm = CAM_COORDS[s][2]; // //현재 카메라의 모델
	int ny = cy, nx = cx; //탐색을 위한 변수 선언

	int cv = value;
	for (d = 0; d < 4; d++) {
		cv = value;

		//모델별 방향 갱신
		for (d2 = 1; d2 <= D2[cm][0]; d2++) {
			ny = cy; nx = cx;
			int cd2 = (d + D2[cm][d2]) % 4;
			buf[cd2][0] = 0;//[x][y] = x방향으로 진행할때 y번째를 시야로 쳤는가?
			//모델 별 두번재 방향 갱신
			while (1) {
				ny += D[cd2][0]; nx += D[cd2][1];
				if (1 > ny || ny > M || 1 > nx || nx > N)break;
				if (cField[ny][nx] == 6) break;

				//빈공간이었으면 기록해두고 변환
				if (cField[ny][nx] == 0) {
					buf[cd2][++buf[cd2][0]] = 1;
					cField[ny][nx] = -1;
					cv--;
				}
				else {
					buf[cd2][++buf[cd2][0]] = 0;
				}
				//아니었으면 기록안함.
			}

		}
		for (int p1 = 1; p1 <= M; p1++) {
			for (int p2 = 1; p2 <= N; p2++) {
				cout << cField[p1][p2] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// 호출
		ret = f(s + 1, cField, cv);
		if (mx > ret) mx = ret;

		//모델별 방향 갱신 취소
		for (d2 = 1; d2 <= D2[cm][0]; d2++) {
			ny = cy; nx = cx;
			int cd2 = (d + D2[cm][d2]) % 4;

			//모델 별 두번재 방향 갱신 취소
			for (int idx = 1; idx <= buf[cd2][0]; idx++) {
				ny += D[cd2][0]; nx += D[cd2][1];
				//빈공간이었으면 기록해두고 변환
				if (buf[cd2][idx])cField[ny][nx] = 0;
				//아니었으면 기록안함.
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