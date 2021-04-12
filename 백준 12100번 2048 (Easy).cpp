#include <iostream>
#include <vector>
using namespace std;
#define ffarr for (i = 1; i <= N; i++) { for (j = 1; j <= N; j++) { cout << arr[i][j] << " "; }cout << endl; }
#define ffac for (i = 1; i <= N; i++) { for (j = 1; j <= N; j++) { cout << arr_copy[i][j] << " "; }cout << endl; }


int N, arr[22][22] = { 0, };
int d[4][2] = { {-1,0}, {0,1}, {1, 0}, {0, -1} };

vector<int> v;
void cpy(int (*a)[22], int (*b)[22]) {
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) { a[i][j] = b[i][j]; } 
}


int f(int n, int (*arr)[22]) {
	int i, j;
	int ret, mx = -1e9, dir;
	
	for (dir = 0; dir < 4; dir++) {
	//for (dir = 2; dir <= 2; dir++) {
		int arr_copy[22][22] = { 0, };
		cpy(arr_copy, arr);

		for (int width = 1; width <= N; width++) 
		{
			//cout << width << "번째 폭" << endl;
			//초기값 설정
			int cury, curx;
			if (dir == 2) { cury = N, curx = width; }
			if (dir == 3) { cury = width, curx = 1; }
			if (dir == 0) { cury = 1, curx = width; }
			if (dir == 1) { cury = width, curx = N; }

			//cout << "dir : " << dir << " " << cury << " "  << curx << endl;

			//합친 문자열 생성
			int prev = 0, line[22] = { 0, }, cnt = 1;
			while (1 <= cury && cury <= N && 1 <= curx && curx <= N) {
				int cv = arr[cury][curx];

				if (prev != cv) {
					if (prev == 0) prev = cv;
					else { if (cv != 0) { line[cnt++] = prev; prev = cv; } }
				}
				else { if (prev != 0) { line[cnt++] = prev * 2; prev = 0; } }

				cury -= d[dir][0], curx -= d[dir][1];
			}
			if (prev) line[cnt++] = prev;

			//갱신
			//for (i = 1; i < cnt; i++) cout << line[i] << " ";	cout << endl;

			if (dir == 2) { cury = N, curx = width; }
			if (dir == 3) { cury = width, curx = 1; }
			if (dir == 0) { cury = 1, curx = width; }
			if (dir == 1) { cury = width, curx = N; }

			i = 1;
			while (1 <= cury && cury <= N && 1 <= curx && curx <= N) {
				if (i < cnt) 
				{
					///답
					if (mx < line[i]) mx = line[i];
					//

					arr_copy[cury][curx] = line[i];
				}
				else arr_copy[cury][curx] = 0;
				cury -= d[dir][0], curx -= d[dir][1], i++;
			}
		}
		//ffac;
		//cout << "답 : ";
		//for (j = 0; j < v.size(); j++) cout << v.at(j) << " ";
		//cout << dir << " : " << mx << endl;
		if (n < 4) {
			v.push_back(dir);
			ret = f(n + 1, arr_copy);
			if (mx < ret) mx = ret;
			v.pop_back();
		}

	}
	return mx;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) { cin >> arr[i][j]; }
	cout << f(0, arr) << endl;
}