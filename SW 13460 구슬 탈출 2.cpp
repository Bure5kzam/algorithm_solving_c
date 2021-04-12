//1.4방향 완전 탐색에서 R구슬 경로 찾기 + 시간
//2.4방향 완전 탐색에서 B구슬 경로 찾기 + 시간
//둘이 시간 비교

#include <iostream>
#include <vector>
using namespace std;
int N, M, target[2];
vector<int>v, v2;
char arr[11][11] = { 0, };
int d[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
};
int priority[4][2] = { {0,2}, {3,1}, {2,0}, {1,3} };

int FindPath3(int n, int pos[]) {
	int i, j, mn=1e9;

	if (n > 10) return 1e9;


	int ret = 0;
	//pos[4] 
	//4방향으로 돌리기 시도
	for (int dir = 0; dir < 4; dir++) {	
		int npos[4], result = 0;
		int nposRange[2][4]; // mny, mnx, mxy, mxx
		
		for (i = 0; i < 4; i++)  npos[i] = pos[i];
		//돌렸을 때 범위 확인

		for (i = 0; i < 2; i++) {
			int curPosy = pos[i * 2];
			int curPosx = pos[i * 2 + 1];

			nposRange[i][0] = nposRange[i][2] = curPosy;
			nposRange[i][1] = nposRange[i][3] = curPosx;

			while (arr[nposRange[i][0] + d[dir][0]][nposRange[i][3] + d[dir][1]] != '#') {
				//cout << nposRange[i][0] << " " << nposRange[i][3] << endl;
				nposRange[i][0] += d[dir][0];
				nposRange[i][3] += d[dir][1];
				if (arr[nposRange[i][0]][nposRange[i][3]] == 'O') {
					//현재 dir 방향으로 검사
					//cout << "find 0 " << endl;
					//cout << curPosy << " " << curPosx << endl;
					//cout << nposRange[i][0] << " " << nposRange[i][0]<< endl;
					if (i == 0) result = n;
					else if (i == 1) result = 1e9;
					
					break;
				}
			}
			//cout << endl;

			while (arr[nposRange[i][2] - d[dir][0]][nposRange[i][1] - d[dir][1]] != '#') {
				nposRange[i][2] -= d[dir][0];
				nposRange[i][1] -= d[dir][1];
			}

			if (nposRange[i][0] > nposRange[i][2]) {
				int tmp = nposRange[i][0];
				nposRange[i][0] = nposRange[i][2];
				nposRange[i][2] = tmp;
			}
			if (nposRange[i][1] > nposRange[i][3]) {
				int tmp = nposRange[i][1];
				nposRange[i][1] = nposRange[i][3];
				nposRange[i][3] = tmp;
			}
			/*for (j = 0; j < n; j++) cout << "   ";
			for (j = 0; j < 4; j++) cout << nposRange[i][j] << " ";
			cout << "//";*/
		}
		//cout << endl;
		if (result != 0) { 
			if (result == 1e9) continue;
			if (mn > result)mn = result;
			//cout << "v : " << result << " : ";
			/*for (i = 0; i < v.size(); i++) cout << v.at(i) << " ";
			cout << dir;
			cout << endl;
			for (i = 0; i < v2.size(); i++) cout << v2.at(i) << " ";
			cout << endl;*/
		}

		bool ch = true;
		for (i = 0; i < 4; i++) if (nposRange[0][i] != nposRange[1][i]) { ch = false; break; }
		if (ch) {
			v2.push_back(0);
			int mny = nposRange[0][0], mnx = nposRange[0][1], mxy = nposRange[0][2], mxx = nposRange[0][3];
			switch (dir) {
			
			case 0:
				if (pos[priority[dir][0]] < pos[priority[dir][1]]) { npos[0] = nposRange[0][0], npos[1] = nposRange[0][1], npos[2] = nposRange[0][0] - d[dir][0], npos[3] = nposRange[0][1]; }
				else { npos[0] = nposRange[0][0] - d[dir][0], npos[1] = nposRange[0][1], npos[2] = nposRange[0][0], npos[3] = nposRange[0][1]; }
				break;
			case 1:
				if (pos[priority[dir][0]] < pos[priority[dir][1]]) { npos[0] = mny, npos[1] = mxx, npos[2] = mny, npos[3] = mxx - d[dir][1]; }
				else { npos[0] = mny, npos[1] = mxx - d[dir][1], npos[2] = mny, npos[3] = mxx; }
				break;
			case 2:
				if (pos[priority[dir][0]] < pos[priority[dir][1]]) { npos[0] = mxy, npos[1] = mnx, npos[2] = mxy - d[dir][0], npos[3] = mnx; }
				else { npos[0] = mxy - d[dir][0]; npos[1] = mnx; npos[2] = mxy; npos[3] = mnx; }
				break;
			case 3:
				if (pos[priority[dir][0]] < pos[priority[dir][1]]) { npos[0] = mny, npos[1] = mnx, npos[2] = mny, npos[3] = mnx -d[dir][1]; }
				else { npos[0] = mny;npos[1] = mnx - d[dir][1];	npos[2] = mny;	npos[3] = mnx; }
				break;
			}
		}
		else {
			v2.push_back(1);
			switch (dir) {
			case 0:
				npos[dir % 2] = nposRange[0][0];
				npos[2 + dir % 2] = nposRange[1][0];
				break;
			case 1:
				npos[dir % 2] = nposRange[0][3];
				npos[2 + dir % 2] = nposRange[1][3];
				break;
			case 2:
				npos[dir % 2] = nposRange[0][2];
				npos[2 + dir % 2] = nposRange[1][2];
				break;
			case 3:
				npos[dir % 2] = nposRange[0][1];
				npos[2 + dir % 2] = nposRange[1][1];
				break;
			}
		}
		ch = true;
		for (i = 0; i < 4; i++) if (pos[i] != npos[i]) ch = false;
		if (!ch) {
			v.push_back(dir);


			//for (i = 0; i < v.size(); i++) cout << v.at(i) << " ";
			//cout << endl;

			ret = FindPath3(n + 1, npos);

			if (ret < mn) mn = ret;


			v.pop_back();
		}
		v2.pop_back();
	}
	return mn;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, pos[4] = { 0, }, ret = 0;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> arr[i][j];
			switch (arr[i][j])
			{
			case 'R':
				pos[0] = i;
				pos[1] = j;
				break;
			case 'B':
				pos[2] = i;
				pos[3] = j;
				break;
			case 'O':
				target[0] = i;
				target[1] = j;
			}
		}
	}
	//for (i = 0; i < 1; i++) cout << FindPath(ipos[i][0], ipos[i][1], 0, 0,0) << endl;
	 ret = FindPath3(1, pos);
	 if (ret == 1e9) cout << -1 << endl;
	 else cout << ret << endl;

}