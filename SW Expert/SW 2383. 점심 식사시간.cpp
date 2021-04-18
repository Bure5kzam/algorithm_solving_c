#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector <int> vec[2], wait[2];
int N, man[11][2], man_cnt = 0, door[2][3], door_cnt = 0, dist[11] = { 0, }, target[11] = { 0, };
void getDistance(int mani, int doori) {
	dist[mani] = abs(door[doori][0] - man[mani][0]) + abs(door[doori][1] - man[mani][1]);
	target[mani] = doori;
}
int Simulation() {
	int i, j, mani, doori, time=0;
	int unVisited = man_cnt;
	while (unVisited) {
		time++;
		for (doori = 0; doori < 2; doori++) {
			int cnt = 3, idx = 0;
			while (idx < vec[doori].size() && cnt != 0) {
				//cout << idx << " " << endl;
				if (vec[doori].at(idx)) {
					if (vec[doori].at(idx) != 1) { vec[doori].at(idx++)--; cnt--; }
					else { vec[doori].erase(vec[doori].begin() + idx); unVisited--; }
				}
			}
		}
		for (doori = 0; doori < 2; doori++) {
			while (vec[doori].size() < 3 && !wait[doori].empty()) {
				int poped = wait[doori].at(0);
				vec[doori].push_back(poped);
				wait[doori].erase(wait[doori].begin());
			}
		}

		for (mani = 0; mani < man_cnt; mani++) {
			if (dist[mani] != -1) {
				dist[mani]--;
				if (dist[mani] == 0) wait[target[mani]].push_back(door[target[mani]][2]);//vec[target[mani]].push_back(door[target[mani]][2]);
				
			}
		}

	}
	return time;
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, tmp, min= 1e9, ret,t ,tc;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> N;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				cin >> tmp;
				if (tmp == 1) { man[man_cnt][0] = i; man[man_cnt++][1] = j; }
				else if (tmp != 0) { door[door_cnt][0] = i; door[door_cnt][1] = j; door[door_cnt++][2] = tmp; }
			}
		}
		
		for (i = 0; i < (1 << man_cnt); i++) {
		//for (i = 56; i <= 56; i++) {
		
			for (j = 0; j < man_cnt; j++) {
				getDistance(j, (i & (1 << j)) == 0 ? 0 : 1);
			}
			for (j = 0; j < 2; j++) vec[j].clear();
			ret = Simulation();
			if (min > ret) {
				min = ret;
			//	cout << ret << " " << i << endl;
			}
		}
		
		
	
		cout << "#" << tc << " " << min <<endl;
		man_cnt = 0;
		door_cnt = 0;
		min = 1e9;
	}
}