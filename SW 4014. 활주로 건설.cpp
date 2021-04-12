#include <iostream>
using namespace std;
int N, X;
int arr[22][22] = { 0, };

int Row(int y) {
	int i, j, prev[2] = { arr[y][1], arr[y][N] }, start[2] = { 1 , N}, posX, revPosX;
	bool visited[21] = { 0, };
	for (posX = 2; posX <= N; posX++) {
		revPosX = N - posX+1;

		if (prev[0] < arr[y][posX]) {
			if (arr[y][posX] - prev[0] > 1) return 0;
			else {
				if ((posX - 1) - start[0] + 1 >= X) {
					for (i = 1; i <= X; i++) {
						if (!visited[posX - i]) visited[posX - i] = true;
						else return 0;
					}
					start[0] = posX;
				}
				else return 0;
			}
		}
		
		if (prev[0] != arr[y][posX]) {
			prev[0] = arr[y][posX];
			start[0] = posX;
		}

		if (prev[1] < arr[y][revPosX]) {
			if (arr[y][revPosX] - prev[1] > 1) return 0;
			else {
				if (start[1] - revPosX >= X) {
					for (i = 1; i <= X; i++) {
						if (!visited[revPosX + i]) visited[revPosX + i] = true;
						else return 0;
					}
					
				}
				else return 0;
			}
		}
		if (prev[1] != arr[y][revPosX]) {
			prev[1] = arr[y][revPosX];
			start[1] = revPosX;
		}

	}
	return 1;
}
int Col(int x) {
	int i, j, prev[2] = { arr[1][x], arr[N][x] }, start[2] = { 1 , N }, posX, revPosX;
	bool visited[21] = { 0, };
	for (posX = 2; posX <= N; posX++) {
		revPosX = N - posX + 1;

		if (prev[0] < arr[posX][x]) {
			if (arr[posX][x] - prev[0] > 1) return 0;
			else {
				if ((posX - 1) - start[0] + 1 >= X) {
					for (i = 1; i <= X; i++) {
						if (!visited[posX - i]) visited[posX - i] = true;
						else return 0;
					}
					start[0] = posX;
				}
				else return 0;
			}
		}
		if (prev[0] != arr[posX][x]) {
			prev[0] = arr[posX][x];
			start[0] = posX;
		}

		if (prev[1] < arr[revPosX][x]) {
			if (arr[revPosX][x] - prev[1] > 1) return 0;
			else {
				if (start[1] - revPosX >= X) {
					for (i = 1; i <=X ; i++) {
						if (!visited[i+revPosX]) visited[i+revPosX] = true;
						else return 0;
					}
					start[1] = revPosX;
				}
				else return 0;
			}
		}
		if (prev[1] != arr[revPosX][x]) {
			prev[1] = arr[revPosX][x];
			start[1] = revPosX;
		}
		

	}
	return 1;
}
int main() {
	int i, j, sum = 0, t, tc;
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> N >> X;
		sum = 0;
		for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) { cin >> arr[i][j]; }
		for (i = 1; i <= N; i++) {
			sum += Col(i) + Row(i);
		}
		cout << "#" << tc << " " << sum << endl;
	}
}