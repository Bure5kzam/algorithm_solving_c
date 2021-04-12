#include <iostream>
#include <algorithm>
#define cond cury>0 && cury <=N && curx >0 && curx <=M
using namespace std;
int N, M, d[4][2] = { {-1,0}, {0,1}, {1,0}, {0, -1} };
int arr[12][12] = { 0, }, edge[300][3] = { 0, }, edgeIdx[300] = { 0, }, islandNum = 1, er = 0;
int set[12] = { 0, }, r[12] = { 0, }, visited[12] = { 0, };
int findParent(int x) {
	int cur = set[x];
	while(set[cur] != cur) {
		cur = set[cur];
	}
	//set[x] = x;
	return cur;
}
void unionSet(int x, int y, int &remain) {
	int p1 = findParent(x);
	int p2 = findParent(y);
	remain--;
	if (r[p1] > r[p2])set[p2] = p1;
	else {
		set[p1] =p2;
		if (r[p1] == r[p2]) r[p2]++;
	}
}
void BFS(int iy, int ix);
int cmp(int y, int x) {
	return edge[y][0] < edge[x][0];
}
void findBridge(int y, int x, int dir) {
	//cout << ": " << y << " " << x << " " << dir << endl;
	int cnt, cury = y + d[dir][0], curx = x + d[dir][1], length = 0;


	while (arr[cury][curx] == 0 && cond) {
		cury += d[dir][0];
		curx += d[dir][1];
		length++;
	}
	//1�̸� bfs ���� �� ������ �ֱ�
			//�ƴϸ� 
			//0�̰ų� 2���� ���̰� ���� ��� fail
			//������ �ְ� ��
	if (arr[cury][curx] == 0 || length < 2) return;
	else {
		if (arr[cury][curx] == 1) {
			++er;
			edgeIdx[er] = er;
			edge[er][0] = length;
			edge[er][1] = arr[y][x]; //������, ���� ��
			edge[er][2] = islandNum + 1; // ���� ��
			BFS(cury, curx);
		}
		else {
			++er;
			edgeIdx[er] = er;
			edge[er][0] = length;
			edge[er][1] = arr[y][x]; //������, ���� ��
			edge[er][2] = arr[cury][curx]; // ���� ��
		}
	}
}
void BFS(int iy, int ix) {
	islandNum++;
	int q[222] = { 0, }, front = 0, rear = 0, i;
	int bq[333] = { 0, }, bf = 0, br = 0;
	q[++rear] = iy;
	q[++rear] = ix;
	arr[iy][ix] = islandNum;

	while (front < rear) {
		int popy = q[++front];
		int popx = q[++front];
		for (i = 0; i < 4; i++) {
			int ny = popy + d[i][0], nx = popx + d[i][1];
			if (ny <= 0 || ny > N || nx <= 0 || nx > M)continue;

			//���� Ž������ ã�´�.
			if (arr[ny][nx] == 1) {
				q[++rear] = ny;
				q[++rear] = nx;
				arr[ny][nx] = islandNum;
			}

			//�ٸ��� ���� �� �ִ°��� ã�´�.
			if (arr[ny][nx] == 0) {
				//cout << ny << " " << nx << endl;
			//	findBridge(ny, nx, i);
				bq[++br] = popy;
				bq[++br] = popx;
				bq[++br] = i;
			}
		}
	}

	while (bf <= br) {
		int popy = bq[++bf];
		int popx = bq[++bf];
		int popdir = bq[++bf];

		//�긴�� Ž��
		findBridge(popy, popx, popdir);
	}
}
int main() {
	int i, j;
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	int y, x;
	//���ٰ� 1�߰��ϸ� bfs
	for (y = 1; y <= N; y++) {
		for (x = 1; x <= M; x++) {
			//bfs���� �ٸ� ���� �����ϰ� 1���� 2�� ����
			if (arr[y][x] == 1) BFS(y, x);
		}
	}

	/*for (int p1 = 1; p1 <= N; p1++) {
		for (int p2 = 1; p2 <= M; p2++) {
			cout << arr[p1][p2] << " ";
		}
		cout << endl;
	}*/

	//���� �ٸ��� ���
	/*for (int p1 = 1; p1 <= er; p1++) {
		for (int p2 = 0; p2 < 3; p2++) {
			cout << edge[p1][p2] << " ";
		}
		cout << endl;
	}*/
	//�ٸ� �ε����� �ٸ�������[0] �������� ����
	/*for (int p1 = 1; p1 <= er; p1++) cout << edgeIdx[p1] << " ";
	cout << endl;*/
	if (er > 0)sort(edgeIdx + 1, (edgeIdx + er), cmp);
	/*for (int p1 = 1; p1 <= er; p1++) cout << edgeIdx[p1] << " ";
	cout << endl;*/


	for (i = 2; i <= islandNum; i++) {
		set[i] = i;
		r[i] = 1;
	}
	//��� ���� �θ� ã�������� ����
	int remain = islandNum, ans = 0, routed[10] = { 0, };
	for (int i = 1; i <= er; i++) {
		int cl = edge[edgeIdx[i]][0];
		int ci1 = edge[edgeIdx[i]][1];
		int ci2 = edge[edgeIdx[i]][2];
		//cout << cl << " " << ci1 << " " << ci2 << " ";
		if (findParent(ci1) != findParent(ci2)) {
			ans += cl;
			unionSet(ci1, ci2, remain);
			//cout << "��" << " ";
		}
		//cout << endl;
	}
	for (j = 3; j <= islandNum; j++) {
		if (findParent(j) != findParent(j - 1))break;
	}
	if (islandNum+1 == j) cout << ans << endl;
	else cout << -1 << endl;

}