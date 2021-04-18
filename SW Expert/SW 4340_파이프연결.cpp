#include <iostream>
using namespace std;
int N, arr[53][53] = { 0, };
int cnt = 5;
int convert[7] = { -1,0,0,1,1,1,1 };
int d[4][2][3][3] = {
{
	{
		{1,},
		{ 1, 0 , 0}
	},
	{
		{2,},
		{0, 1,3},
		{0, -1,1}
	}
},
{
	{
		{1,},
		{0, -1, 1}
	},
	{
		{2,},
		{-1,0, 2},
		{1,0,0}
	}
},
{
	{
		{1,},
		{-1, 0,2}
	},
	{
		{2,},
		{0,-1,1},
		{0,1,3}
	}
},
{
	{
		{1,},
		{0, 1,3}
	},
	{
		{2,},
		{-1,0,2},
		{1,0,0}
	}
},
};

int DFS(int y, int x, int prev, int l) {
	int ret = 1e9, min = 1e9, i, j;
	if (y == N && x == N + 1) {
		return l;

	}
	else {
		int v = arr[y][x];
		arr[y][x] = cnt++;
		for (i = 1; i <= d[prev][v][0][0]; i++) {
			int ny = y + d[prev][v][i][0];
			int nx = x + d[prev][v][i][1];
			if (arr[ny][nx] != -1 && arr[ny][nx] < 5) {
				ret = DFS(ny, nx, d[prev][v][i][2], l + 1);
				if (ret < min) min = ret;  
			}
		}
		cnt--;
		arr[y][x] = v;
		return min;
	}
}
int main() {
	int i, j, tc, t, tmp;
	cin >> tc;
	for (t = 1; t <= tc; t++) {
		cin >> N;
		for (i = 0; i <= N + 1; i++) {
			arr[i][0] = -1;
			arr[i][N + 1] = -1;
			arr[0][i] = -1;
			arr[N + 1][i] = -1;
		}

		for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
			cin >> tmp;
			arr[i][j] = convert[tmp];
		}
		arr[N][N + 1] = 1;
		arr[N][N + 2] = -1;
		cnt = 5;
		cout << "#" << t << " " << DFS(1, 1, 3, 1) - 1 << endl;
	}
}