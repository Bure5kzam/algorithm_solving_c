#include <iostream>
using namespace std;
int N, W, H, ans=1e9;
int q[40000][2];

void BFS(int arr[][17],int *top, int y, int x, int visited[][17]) {
	int  front=0, rear = 0;
	q[++rear][0] = y;
	q[rear][1] = x;
	while (front < rear) {
		int cy = q[++front][0], cx = q[front][1];
		if (visited[cy][cx] || cy < top[cx] || cy > H || cx <= 0 || cx > W) continue;
		visited[cy][cx] = true;
		
		for (int j = 1; j < arr[cy][cx]; j++) {
			
				q[++rear][0] = cy + j;
				q[rear][1] = cx;
			
			
				q[++rear][0] = cy - j;
				q[rear][1] = cx;
			
			
				q[++rear][0] = cy;
				q[rear][1] = cx + j;
			
			
				q[++rear][0] = cy;
				q[rear][1] = cx - j;
			
		}
	}
}
void MakeArray(int arr[][17], int narr[][17], int* ntop, int visited[][17]) {
	for (int x = 1; x <= W; x++) {
		ntop[x] = H;
		
		for (int y = H; y >=1; y--) {
			narr[y][x] = 0;
			if (arr[y][x] != 0 && !visited[y][x]) narr[ntop[x]--][x] = arr[y][x];
		}
		ntop[x]++;
		
	}
}
int getAnswer(int* top) {
	int sum = 0;
	for (int i = 1; i <= W; i++) sum += H - top[i] + 1;
	return sum;
}
void comb2(int arr[][17], int* top, int k, int s) {
	int nC,i,j, q[300][2] = { 0, };
	int narr[17][17], ntop[17];
	//pushRoute(k);
	if (k < N) {
		for (nC = 1; nC <= W; nC++) { // s => W;
			int visited[17][17] = { 0, };
			if (top[nC] != H + 1) {
				//檬扁拳 array2, ntop, visited
				BFS(arr,top, top[nC], nC, visited); // visited 肯己 积己
			/*for (int pi = 1; pi <= H; pi++) {
					for (int pj = 1; pj <= W; pj++) {
						cout << visited[pi][pj] << " ";
					}
					cout << endl;
				}
				cout << endl;*/
				MakeArray(arr, narr, ntop, visited); // narray, ntop 积己

				/*for (int pi = 1; pi <= H; pi++) {
					for (int pj = 1; pj <= W; pj++) {
						cout << narr[pi][pj] << " ";
					}
					cout << endl;
				}
				cout << endl;*/

				comb2(narr, ntop, k + 1, s);

			}
		}
		comb2(arr, top, k + 1, s);
	}
	else {
		int ret = getAnswer(top);
		if (ret < ans) {
			ans = ret;
		/*	for (int i = 1; i <= W; i++) cout << H-top[i]+1;
			cout << endl;*/
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int t, tc, i, j;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> N >> W >> H;
		ans = 1e9;
		int arr[17][17] = { 0, }, top[17] = { 1, };
		for (i = 0; i < 17; i++) top[i] = 1;

		for (i = 1; i <= H; i++) {
			for (j = 1; j <= W; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 0) top[j] = i + 1;
			}
		}
		comb2(arr, top, 0, 1);
		cout << "#" <<tc << " " << ans << endl;
	}
}