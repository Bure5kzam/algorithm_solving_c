#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[2][4];
int arr[2][600][600] = { 0, };
int N, M, K;
int d[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0, -1}
};
void push(int ver, int y, int x, int t, int len) {
	vec[ver][0].push_back(y);
	vec[ver][1].push_back(x);
	vec[ver][2].push_back(t);
	vec[ver][3].push_back(len);
}
void erase(int ver, int i) {
	vec[ver][0].erase(vec[ver][0].begin() + i);
	vec[ver][1].erase(vec[ver][1].begin() + i);
	vec[ver][2].erase(vec[ver][2].begin() + i);
	vec[ver][3].erase(vec[ver][3].begin() + i);
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, t, tc;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {

		for (i = 0; i < 2; i++) {
			for (j = 0; j < 4; j++) {
				vec[i][j].clear();
			}
		}
		for (i = 0; i < 600; i++) {
			for (j = 0; j < 600; j++) {
				for (int k = 0; k < 2; k++) {
					arr[k][i][j] = 0;
				}
			}
		}
		cin >> N >> M >> K;
		for (i = 155; i < N + 155; i++) {
			for (j = 155; j < M + 155; j++) {
				cin >> arr[0][i][j];
				if (arr[0][i][j] != 0) {
					push(0, i, j, arr[0][i][j], arr[0][i][j]);
					arr[1][i][j] = -1;
				}
			}
		}

		for (int time = 1; time <= K; time++) {
			//q2 돌기
			i = 0;
			while (i < vec[1][0].size()) {
				for (int j = 0; j < 4; j++) {
					int cy = vec[1][0].at(i) + d[j][0];
					int cx = vec[1][1].at(i) + d[j][1];
					if (arr[1][cy][cx] == 0) {
						push(0, vec[1][0].at(i) + d[j][0], vec[1][1].at(i) + d[j][1], vec[1][2].at(i), vec[1][2].at(i) + time);
						arr[1][cy][cx] = time;
						arr[0][cy][cx] = vec[0][0].size() - 1;
					}
					else if (arr[1][cy][cx] == time) {
						if (vec[0][2].at(arr[0][cy][cx]) < vec[1][2].at(i)) {
							vec[0][2].at(i) = vec[1][2].at(i);
							vec[0][3].at(i) = vec[1][2].at(i) + time;
						}

					}
				}
				if (vec[1][3].at(i) == time) {
					erase(1, i);
					i--;
				}

				i++;
			}

			//q1 돌기
			i = 0;
			while (i < vec[0][0].size()) {
				if (vec[0][3].at(i) == time) {
					push(1, vec[0][0].at(i), vec[0][1].at(i), vec[0][2].at(i), vec[0][2].at(i) + time);
					erase(0, i);
					i--;
				}
				i++;
			}
			/*cout << "time : " << time << " " << vec[0][0].size() << " " << vec[1][0].size() << endl;
			for (i = 0; i < vec[0][0].size(); i++)cout << vec[0][0].at(i) << " ";
			cout << endl;
			for (i = 0; i < vec[0][1].size(); i++)cout << vec[0][1].at(i) << " ";
			cout << endl;
			for (i = 0; i < vec[0][2].size(); i++)cout << vec[0][2].at(i) << " ";
			cout << endl;
			for (i = 0; i < vec[0][3].size(); i++)cout << vec[0][3].at(i) << " ";
			cout << endl;

			for (i = 0; i < vec[1][0].size(); i++)cout << vec[1][0].at(i) << " ";
			cout << endl;
			for (i = 0; i < vec[1][1].size(); i++)cout << vec[1][1].at(i) << " ";
			cout << endl;
			for (i = 0; i < vec[1][2].size(); i++)cout << vec[1][2].at(i) << " ";
			cout << endl;
			for (i = 0; i < vec[1][3].size(); i++)cout << vec[1][3].at(i) << " ";
			cout << endl;
			cout << endl;*/

		}
		cout << "#" << tc << " " << vec[1][0].size() + vec[0][0].size() << endl;
	}
}