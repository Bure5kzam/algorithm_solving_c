#include <iostream>
#include <vector>
using namespace std;
#define M 2004
int arr[M][M] = { 0, };
bool visited[1004] = { 0, };
int node[1004][4] = { 0, }, top=1, vc = 0;
int d1[4][3] = {
	{1,0,1},
	{-1,0,0},
	{0,-1,3},
	{0,1,2}
};
int d2[4][3][3] = {
	{{2,0, 1}, {1,-1, 3}, {1,1, 2}},
	{{-2,0, 0}, {-1,-1, 3}, {-1,1,2}},
	{{0,-2, 3}, {1,-1, 1}, {-1,-1,0}},
	{{0,2, 2}, {1,1, 1}, {-1,1, 0}},
};
void push(int Y, int X, int D, int K) {
	node[top][0] = Y;
	node[top][1] = X;
	node[top][2] = D;
	node[top++][3] = K;
}
void erase(int i) {
	visited[i] = true;
	vc--;
}
int d1find(int i) {
	int sum = 0;
	int ny = node[i][0] + d1[node[i][2]][0];
	int nx = node[i][1] + d1[node[i][2]][1];
	if (arr[ny][nx] != 0 && !visited[i] && node[arr[ny][nx]][2] == d1[node[i][2]][2]) {
		int ii = arr[ny][nx];
		/*cout << "df1 : " << i << " " << ii << endl;*/
		arr[node[i][0]][node[i][1]] = 0;
		arr[ny][nx] = 0;
		sum = node[i][3]+ node[i][3];
		erase(i); erase(ii);
	}
	return sum;
}
void move(int i) {
	int cy = node[i][0], cx = node[i][1];
	int ny = node[i][0] + d1[node[i][2]][0], nx = node[i][1] + d1[node[i][2]][1];
	arr[cy][cx] = 0;
	if (ny > 1000 + M / 2 || nx > 1000 + M / 2 || nx < -1000 + M / 2 || ny < -1000 + M / 2) {
		/*cout << "move : " << i << " : " << cy <<" " <<  cx << endl;*/
		erase(i);
		return;
	}
	arr[ny][nx] = i;
	node[i][0] = ny;
	node[i][1] = nx;
}
int d2find(int i) {
	int sum = 0;
	for (int j = 0; j < 3; j++) {
		int ny = node[i][0] + d2[node[i][2]][j][0];
		int nx = node[i][1] + d2[node[i][2]][j][1];
		if (arr[ny][nx] != 0 && !visited[i] && node[arr[ny][nx]][2] == d2[node[i][2]][j][2]) {
			int ii = arr[ny][nx];
			arr[ny][nx] = 0;
	/*		cout << "df2 : " << i << " " << ii << endl;*/
			sum += node[ii][3];
			erase(ii);
		}
	}
	if (sum) { erase(i); sum += node[i][3]; arr[node[i][0]][node[i][1]] = 0; }
	return sum;
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, tc, t, sum=0;
	int Y, X, D, K;
	int N;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> N;
		vc = N;
		top = 1;
		sum = 0;
		for (i = 1; i <= N; i++) {
			cin >> X >> Y >> D >> K;
			push(Y + M / 2, X + M / 2, D, K);
			arr[Y + M / 2][X + M / 2] = i;
		}
		while (vc>0) {
			for (i = 1; i <= N; i++) {
				if (!visited[i])sum += d1find(i);
			}
	/*		cout << "r1 : " << sum < " ";*/
			for (i = 1; i <= N; i++) {
				if (!visited[i])sum += d2find(i);
			}
	/*		cout << "r2 : " << sum << " ";*/
			for (i = 1; i <= N; i++) {
				if (!visited[i])move(i);
			}
			/*
			cout << vc << endl;
			for (i = 1; i <= N; i++) {
				cout << (char)(i + 'A' - 1) << " ";
				for (j = 0; j < 4; j++) { if(j<=1)cout << node[i][j] - M / 2 << " ";else cout << node[i][j]<< " ";}
				cout << " : " << visited[i] << endl;
			}
			cout << sum << endl;
			*/
			
		}
		cout << "#" << tc << " " << sum << endl;

		for (i = 1; i <= N; i++) {
			for (j = 0; j < 4; j++)node[i][j] = 0;
			visited[i] = false;
		}
		/*for (i = 0; i < M; i++) for (j = 0; j < M; j++) { if (arr[i][j]) cout << i << " " << j << endl; }*/
	}
}

/*
*
1
14
-6 5 3 1
-3 5 2 1
-5 2 1 1
3 5 3 1
5 7 1 1
6 7 3 1
7 5 2 1
5 3 0 1
-4 -4 1 1
-4 -6 0 1
5 -3 2 1
4 -6 0 1
6 -4 1 1
9 -7 2 1
*/