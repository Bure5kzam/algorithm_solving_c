#include <iostream>
using namespace std;
/*
* D : 4���� Ž��
* dp : Ž���� ��� ����
*/
int N, F[511][511] = { 0, };
int D[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} };
int dp[511][511];

//DFS : cy, cx ��ǥ�κ��� ������ �� �ִ� �ִ밪�� ��ȯ
int DFS(int cy, int cx) {
	
	int mx = 1,ret=0;
	int cv = F[cy][cx];

	for (int d = 0; d < 4; d++) {
		int ny = cy + D[d][0], nx = cx + D[d][1];
		//1-1 ���� ����� ����
		if (ny < 1 || ny > N || nx < 1 || nx > N) continue;

		int nv = F[ny][nx];
		//1-2 ���� ���� ���� ������ ������ ����
		if (cv >= nv)continue;

		//1-3 ����
		if (dp[ny][nx] == 0)ret = DFS(ny, nx) + 1;
		else ret = dp[ny][nx] + 1;

		if (mx < ret) mx = ret;
	}
	//2-1 Ž���� ��� ����
	dp[cy][cx] = mx;
	return mx;
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, ans = 0, ret = 0;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> F[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			ret = DFS(i, j);
			if (ans < ret) ans = ret;
		}
	}
	cout << ans << endl;
}