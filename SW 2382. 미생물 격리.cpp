#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int N, M, K;
int arr[2][1001][1001] = { 0, }, arr2[2][1002][5] = { 0, }, cnt=0;
void push2(int i,int k, int ny, int nx, int  n, int  nd) {
	arr2[(i + 1) % 2][k][0] = ny;
	arr2[(i + 1) % 2][k][1] = nx;
	arr2[(i + 1) % 2][k][2] = n;
	arr2[(i + 1) % 2][k][3] = nd;

}
int c[5][3][3] = {
	{{0,0,0,},{0,0,0},{0,0,0}},
	{{-1,1,3},
	{-2,0,2},
	{-1,-1,4}},

	{{2,0,1},
	{1,1,3},
	{1,-1,4}},

	{{1,-1,1},
	{0,-2,4},
	{-1,-1,2}},

	{{1,1,1},
	{0,2,3},
	{-1,1,2}}
};
int d[5][2] = { {0, 0},  { -1,0 } ,{1, 0 }, {0, -1} , {0,1} };
int d_r[6] = { 0, 2, 1, 4, 3 };
int die[1001] = { 0, };
int main() {
	int i, j;
	int tmp[4];
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (i = 1; i <= K; i++) {
		
		for(j = 0 ; j < 4 ; j++)cin >> arr2[0][i][j];
		arr[0][arr2[0][i][0]][arr2[0][i][1]] = i;
	}

	for (int mi = 0; mi < 3; mi++) {
		for (int ki = 1; ki <= K; ki++) {
			int cY = arr2[mi % 2][ki][0], cX = arr2[mi % 2][ki][1], cD = arr2[mi % 2][ki][3];
			if (cY == -1||cY==-2) { if(cY == -1)arr2[(mi + 1) % 2][ki][0] = -1; continue; }
			int nY = cY + d[cD][0];
			int nX = cX + d[cD][1];
			v.clear();
			v.push_back(ki);
			int sum = arr2[mi % 2][ki][2], max = ki;
			for (int ci = 0; ci < 3; ci++) {
				int ny = arr2[mi % 2][ki][0] + c[cD][ci][0];
				int nx = arr2[mi % 2][ki][1] + c[cD][ci][1];
				
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				int ni = arr[mi % 2][ny][nx];
				int nd = arr2[mi % 2][ni][3];

				if (ni != 0 && arr2[mi % 2][ni][0]!=-1 && nd == c[cD][ci][2]) {
					sum += arr2[0][ni][2];
					if (arr2[mi % 2][max][2] < arr2[mi % 2][ni][2]) max = ni;
					v.push_back(ni);
				}
			}
			//만약 합해질게 있다면
			if (sum != arr2[(mi) % 2][ki][2]) {
				int poped = 0;
				while (!v.empty()) {
					poped = v.at(0);
					v.erase(v.begin());
					if (poped == max) {
						push2(mi, poped, nY, nX, sum, arr2[mi % 2][poped][3]);
						arr[(mi) % 2][cY][cX] = 0;
						arr[(mi + 1) % 2][nY][nX] = poped;
						arr2[(mi+1) % 2][poped][0] = -2;
					}
					else {
						arr2[(mi + 1) % 2][poped][0] = -1;
						arr2[(mi) % 2][poped][0] = -1;
					}
					
				}
			}
			else {
				//그냥 이동한다면
				if (nY == 0 || nY == N - 1 || nX == 0 || nX == N - 1) {
					if (arr2[(mi) % 2][ki][2] == 1) {
						arr2[(mi+1) % 2][ki][0] = -1;
						continue;
					}else {
						push2(mi, ki, nY, nX, arr2[mi % 2][ki][2]/2, d_r[cD]);
						arr[(mi + 1) % 2][nY][nX] = ki;arr[(mi) % 2][cY][cX] = 0;
					}
				}
				else {
					push2(mi, ki, nY, nX, arr2[mi % 2][ki][2], cD);
					arr[(mi + 1) % 2][nY][nX] = ki;
					arr[(mi) % 2][cY][cX] = 0;
				}
			}
		}
		cout << "T : " << mi << endl;
		for (i = 0; i < N; i++) { for (j = 0; j < N; j++) { arr[mi % 2][i][j] = 0; cout << arr[(mi + 1) % 2][i][j] << " "; }cout << endl; }
		cout << endl;
	}
}