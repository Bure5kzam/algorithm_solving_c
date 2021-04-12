#include <iostream>
#define print for(i=1;i<=N;i++) {for(j=1;j<=N;j++){ cout << arr[0][i][j] + arr[1][i][j] + arr[2][i][j] << " ";} cout << endl;}
using namespace std;
int arr[3][18][18] = { 0, };
bool check[18][18] = { 0, };
int main() {
	int i, j, N, tmp;
	cin >> N;
	for(i=1;i<=N;i++) for (j = 1; j <= N; j++) cin >> check[i][j];

	arr[0][1][2] = 1;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			//벽 처리
			if (check[y][x]||y==1&&(x<=2)) continue;

			//1. 좌
			if(!check[y][x-1])arr[0][y][x] = arr[0][y][x - 1] + arr[1][y][x - 1];
			//2. 대각
			if(!check[y][x-1]&&!check[y-1][x])arr[1][y][x] = arr[1][y - 1][x - 1] + arr[0][y - 1][x - 1] + arr[2][y - 1][x - 1];
			//3. 상
			if(!check[y-1][x])arr[2][y][x] = arr[1][y - 1][x] + arr[2][y - 1][x];
		}
	}
	
	//print;
	cout << arr[0][N][N] + arr[1][N][N] + arr[2][N][N] << endl;
}