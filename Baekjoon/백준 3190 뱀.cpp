#include <iostream>
using namespace std;
int N, aN,oN;
int arr[111][111] = { 0, }, app[111][2] = { 0, }, order[111][2] = { 0, };
int d[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int main() {
	int i, j; char tmp;
	cin >> N;
	cin >> aN;
	for (i = 0; i < N; i++) { cin >> app[i][0] >> app[i][1]; arr[app[i][0]][app[i][1]] = 4; }
	cin >> oN;
	for (i = 0; i < N; i++) {
		cin >> order[i][0];
		if (oN) order[i][1] = 1;
		else order[i][1] = 2;
	}

	int dir = 1, head[2] = { 1, 1 }, tail[2] = { 1,1 }, time = 0, arr[1][1] = { 1 };
	int ocnt = 0;
	while (1) {
		time++;


		//dir ���� ����
		if(ocnt<oN){
			if (order[ocnt][0] == time) {
				dir = order[ocnt++][1];
			}
		}
		
		//�Ӹ��� �̵�
		int cv = arr[head[0]][head[1]];
		for (i = 0; i < 2; i++) head[i] += d[cv][i];

		//�΋H���� ����
		if (1 > head[0] && head[0] > N && 1 > head[1] && head[1] > N) break;

		//dir �ڱ��� ����
		//��� Ȯ��, �浹 Ȯ�� ( ���� ���� ��ó��)
			//���� ���� ��ġ�� ���� ���� �̵�
		
		int nv = arr[head[0]][head[1]];
		arr[head[0]][head[1]] = dir;

		if (nv != 4) {
			nv
		}
	}

}