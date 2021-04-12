#include <iostream>
using namespace std;
int N, M, K, mn = 1e9;
int arr[51][51] = { 0, };
int turnIdx[10] = { 0, };
int turn[10][3] = {0, };

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void doTurn(int n, int d) {
	int R = turn[n][0], C = turn[n][1], S = turn[n][2];
	int x_mn = C - S, x_mx = C + S, y_mn = R - S, y_mx = R + S;
	int y, x, fst = arr[y_mn][x_mn];
	//È¸Àü
	while (x_mn < x_mx && y_mn < y_mx) {

		if (d == 0) {
			fst = arr[y_mn][x_mn];
			for (y = y_mn; y < y_mx; y++) arr[y][x_mn] = arr[y + 1][x_mn];
			for (x = x_mn; x < x_mx; x++) arr[y_mx][x] = arr[y_mx][x + 1];
			for (y = y_mx; y > y_mn; y--) arr[y][x_mx] = arr[y - 1][x_mx];
			for (x = x_mx; x > x_mn; x--) arr[y_mn][x] = arr[y_mn][x - 1];
			arr[y_mn][x_mn + 1] = fst;
		}
		else {

			fst = arr[y_mn][x_mn];
			for (x = x_mn; x < x_mx; x++) arr[y_mn][x] = arr[y_mn][x+1];
			for (y = y_mn; y < y_mx; y++) arr[y][x_mx] = arr[y + 1][x_mx];
			for (x = x_mx; x > x_mn; x--) arr[y_mx][x] = arr[y_mx][x - 1];
			for (y = y_mx; y > y_mn; y--) arr[y][x_mn] = arr[y-1][x_mn];
			arr[y_mn+1][x_mn] = fst;
		}
		
		//°ª ¹Ù²Ş, ÁÂÇ¥ º¯°æ
		x_mn++;
		y_mn++;
		x_mx--;
		y_mx--;
	}
	/*for (int p1 = 1; p1 <= N; p1++) {
		for (int p2 = 1; p2 <= M; p2++) {
			cout << arr[p1][p2] << " ";
		}
		cout << endl;
	}*/
}

void P(int n) {
	int i, j;
	if (n == K+1) {
		
		//for (i = 1; i <= K; i++) cout << turnIdx[i] << " ";
		//cout << endl;
		for (int y = 1; y <= N; y++) {
			int sum = 0;
			for (int x = 1; x <= M; x++) {
				sum += arr[y][x];
			}
			if (mn > sum) mn = sum;
		}
	}
	
	for (i = n; i <= K; i++) {
		
		
		swap(turnIdx[n], turnIdx[i]);
		//for (j = 0; j <= n; j++) cout << "    ";
		//cout << turn[turnIdx[n]][0] << turn[turnIdx[n]][1] << turn[turnIdx[n]][2] << endl;
		doTurn(turnIdx[n], 0);
		P(n + 1);
		//for (j = 0; j <= n; j++) cout << "    ";
		/*cout << "return" << endl;
		cout << turn[turnIdx[n]][0] << turn[turnIdx[n]][1] << turn[turnIdx[n]][2] << endl;*/
		doTurn(turnIdx[n], 1);
		swap(turnIdx[i], turnIdx[n]);
		
	}
}
int main() {
	int i, j, k, R, C, S;
	cin >> N >> M >> K;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (k = 1; k <= K; k++) {
		cin >> turn[k][0] >> turn[k][1] >> turn[k][2];
		turnIdx[k] = k;
	}
	
	P(1);
	cout << mn << endl;
}

/*
5 6 4
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 3 2
3 3 2
3 3 2
3 3 2


*/