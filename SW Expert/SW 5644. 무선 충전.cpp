#include <iostream>
#include <math.h>
using namespace std;
int d[5][2] = {
	{0,0},
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
int MOVE[2][101] = { 0, }, AP[10][4];
int M, NA, pos[2][2], sum=0, t, tc;
bool status[2][10];
int main() {
	freopen("input.txt", "r", stdin);
	int i, j,k,person, coord, max=0, value=0;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> M >> NA;
		for (j = 0; j < 2; j++) {
			for (i = 0; i < M; i++) cin >> MOVE[j][i];
		}
		for (i = 1; i <= NA; i++) cin >> AP[i][1] >> AP[i][0] >> AP[i][2] >> AP[i][3];



		for (coord = 0; coord < 2; coord++) pos[0][coord] = 1;
		for (coord = 0; coord < 2; coord++) pos[1][coord] = 10;
		status[0][0] = true;
		status[1][0] = true;
		for (i = 1; i <= NA; i++) for (j = 0; j < 2; j++)status[j][i] = false;
		AP[0][2] = 0;
		sum = 0;
		for (i = 0; i <= M; i++) {
			/*
			cout << "time : " << i << endl;
			cout << "A\n X : " << pos[0][1] << " Y : " << pos[0][0] << endl << "B\n X : " << pos[1][1] << " Y : " << pos[1][0] << endl;
			*/
			for (int api = 1; api <= NA; api++) {
				for (person = 0; person < 2; person++) {
					//int distance = sqrt(pow(abs(AP[api][0] - pos[person][0]), 2) + pow(abs(AP[api][1] - pos[person][1]), 2));
					int distance = abs(AP[api][0] - pos[person][0]) + abs(AP[api][1] - pos[person][1]);
					if (distance <= AP[api][2]) status[person][api] = true;
					else status[person][api] = false;
				}
			}

			max = 0;
			value = 0;
			for (int apAi = 0; apAi <= NA; apAi++) {
				for (int apBi = 0; apBi <= NA; apBi++) {
					if (status[0][apAi] && status[1][apBi]) {
						if (apAi != apBi) value = AP[apAi][3] + AP[apBi][3];
						else value = AP[apAi][2];
						if (max < value) max = value;
					}
				}
			}
			//cout << "V : " << max << endl;
			sum += max;
			/*
			for (int p1 = 0; p1 <= NA; p1++) { for (int p2 = 0; p2 < 2; p2++) { cout << status[p2][p1] << " "; }cout << endl; }
			*/
			if (M != i) {
				for (person = 0; person < 2; person++) {
					for (coord = 0; coord < 2; coord++) {
						pos[person][coord] += d[MOVE[person][i]][coord];
					}
				}
			}
		}
		cout << "#" << tc << " " << sum << endl;
	}
}