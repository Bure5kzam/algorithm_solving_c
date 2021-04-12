#include <iostream>
using namespace std;
int tmp[10] = {0,4,2,3,1,5,6,7,8,9 };
int arr[50][10] = { 0, }, mx = -1e9;
int even;
void getScore(int &field,int num, int &score) {
	for (int i = 0; i < num; i++) {
		field <<= 1;
		if (field >= 16) { score += 1; field %= 16; }
	}
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Per(int n) {
	if (n == 9) {
		int e = 0, idx = 0, score=0;

		
		while (e <= even) {
			//이븐갱신
			e++;
			int strike = 0, field= 0;

			while (strike < 3) {
				//해당 이븐에서 스트라이크 3번 나올떄까지 경기 진행
				idx = idx % 9 + 1;
				field += 1;
				switch (arr[e][tmp[idx]]) {
				case 0:
					strike++;
					field -= 1;
					break;
				default:
					getScore(field, arr[e][tmp[idx]], score);
				}
			}
		}
		if (mx < score) mx = score;
		return; 
	}
	//1번을 4번타자로 두고 나머지 순열을 생성
	if (n == 4) Per(n + 1);
	else {
		for (int i = n ; i <= 9; i++) {
			if (i == 4) continue;
			swap(tmp[n], tmp[i]);
			Per(n + 1);
			swap(tmp[i], tmp[n]);
		}
	}
}
int main() {
	int i,j;
	freopen("input.txt", "r", stdin);
	cin >> even;
	for (j = 1; j <= even; j++)for (i = 1; i < 10; i++) cin >> arr[j][i];
	Per(1);
	cout << mx << endl;
}