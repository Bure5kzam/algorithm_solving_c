#include <iostream>
#include <math.h>
using namespace std;
int bin[11] = { 0, };
int adj[12][12] = { 0, }, popular[11] = { 0, };

int bfs(int init, int target, int &remain) {
	int q[12] = { 0, }, front = 0, rear = 0;
	int visited[11] = { 0, }, i ,j, sum=0;
	
	q[++rear] = init;
	

	while (front < rear) {
		int poped = q[++front];
		visited[poped] = true;
		sum += popular[poped];
		remain--;

		for (i = 1; i <= adj[poped][0]; i++) {
			int next = adj[poped][i];
			if (!visited[next] && bin[next] == target) {
				q[++rear] = next;
				visited[next] = true;
			}
		}
	}

	return sum;
}
int main() {
	int N, i, j, mn=1e9;
	cin >> N;
	for (i = 1; i <= N; i++) cin >> popular[i];
	for (i = 1; i <= N; i++) {
		cin >> adj[i][0];
		for (j = 1; j <= adj[i][0]; j++) {
			cin >> adj[i][j];
		}
	}
	for (i = 1; i < (1 << N);i++) {
	
	
		for (j = 0; j < N; j++) {
			//인접리스트만들기

			//바이너리 트리
			//000001~ 111110

			if (i & (1 << j)) {
				bin[j+1] = 1;
			}
			else bin[j+1] = 0;
		}
		int remain = N, sum[2] = { 0, };

		for (int cur = 1; cur <= N; cur++) if (!bin[cur]) { sum[0] = bfs(cur, 0, remain); break; }
		for (int cur = 1; cur <= N; cur++) if (bin[cur]) { sum[1] = bfs(cur, 1, remain); break; }
		if (!remain) {
			//cout << i << " : " << abs(sum[1] - sum[0]) << endl;;
			int ret = abs(sum[1] - sum[0]);
			if (ret < mn) mn = ret;
		}
		//sum[0] = 0인거 bfs 시작
		//sum[1] = 1인거 bfs 시작
		//visitedNum ==0 sum[1] - sum[0];
	}
	if (mn != 1e9) cout << mn << endl;
	else cout << -1 << endl;
}