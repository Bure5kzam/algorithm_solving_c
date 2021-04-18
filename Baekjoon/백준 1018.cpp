#include <iostream>
using namespace std;
int M, N;
char value[2] = {'W', 'B'};
char arr[51][51] = { 0, };

int howMuchColoring(int st, int ed) {
	int  y, x;
	int cnt[2] = { 0, };

	for (y = st; y < st+8; y++) {
		for (x = ed; x < ed+ 8; x++) {
			if (value[(y + x) % 2] != arr[y][x]) cnt[0]++;

			if (value[1 - (y + x) % 2] != arr[y][x]) cnt[1]++;
		}
	}
	return (cnt[0] > cnt[1]) ? cnt[1] : cnt[0];
}
int main() {
	int i, j, ret, min = 1e9;
	cin >> M >> N;

	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) {
		cin >> arr[i][j];
	}

	for (i = 1; i <= M-8+1; i++) {
		for (j = 1; j <= N-8+1; j++) {
			ret = howMuchColoring(i, j);
			if (min > ret) min = ret;
		}
	}


	cout << min << endl;
}


/*
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
*/