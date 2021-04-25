#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> adj[201];
long long int dist[3][201] = { 0, };
//void dj(int init) {
//	q.push
//}
void make_adj(vector<vector<int>> & adjlist) {
	for (auto & e : adjlist) {
		adj[e.at(0)].push_back(make_pair(e.at(1), e.at(2)));
		adj[e.at(1)].push_back(make_pair(e.at(0), e.at(2)));
	}
}
void dj(int n, long long int* d){
	priority_queue<pair<int, int>> pq;
	d[n] = 0;
	pq.push(make_pair(n, 0));
	while (!pq.empty()) {
		int cn = pq.top().first, cv = -1 * pq.top().second;
		pq.pop();

		for (auto & e : adj[cn]) {
			int nn = e.first, nv = e.second;
			if (cv + nv > d[nn]) continue;
			d[nn] = cv + nv;
			pq.push(make_pair(nn, -(cv + nv)));
		}
		
		cout << "pq" << endl;
		for (priority
	}
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0, i, j;
	make_adj(fares);
	for (j = 0; j < 3; j++) {
		for ( i = 1; i <= n; i++) {
			dist[j][i] = 1e9;
		}
	}

	int initNode[3] = { s, a, b };
	for (i = 0; i < 3; i++) {
		dj(initNode[i], (long long int *)dist[i]);
	}

	int mn = 1e9;
	long long int ret = 0;
	for (i = 1; i <= n; i++) {
		ret = dist[1][i] + dist[2][i] + dist[0][i];
		if (mn > ret) mn = ret;
	}
	cout << mn << endl;
	return answer;
}

int main() {
	vector<vector<int>> v1 = { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} };
	solution(7 , 3, 4, 1,v1);
	return 0;
}