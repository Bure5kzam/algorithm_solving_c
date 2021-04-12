/*
* 궁수 배치 경우의 수 확정될 때마다
* 궁수별 탐색
* 궁수별 삭제하며 점수 추가
* 적 내려오기
* 적 수0되면 종료
*/

#include <iostream>
#include <vector>
using namespace std;
int arr[17][17] = { 0, }, arr2[17][17] = { 0, };
int N, M, D;
void Detect(int D, vector<pair<int,int>> &target, int pos, int level) {
	int y = 1+N-level, x = pos, cd = 1;
	int i;
	bool check = false;

	while (cd<=D) {
		int cx = pos - cd, cy = y;
		for (i = 1; i <= cd; i++) {
			cx += 1;
			cy -= 1;
			if (arr2[cy][cx]&&cx>0 && cx<=M && cy <=N && cy>=1) {
				if (arr2[cy][cx] == 1) {target.push_back(make_pair(cy, cx));	return;	}
			}
		}
		for (i = 1; i < cd; i++) {
			cx += 1;
			cy += 1;
			if (arr2[cy][cx]&&cx>0 && cx<=M && cy <= N) {
				if (arr2[cy][cx]) { target.push_back(make_pair(cy, cx));	return; }
			}
		}
		cd++;
	}
	
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, k, l, head = 0, pos[3] = {0, }, max=0;
	vector<int> v[17];
	vector<int> v2[17];
	cin >> N >> M >> D;
	//벡터에 사로별로 삽입
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) head++;
		}
	}
	for (i = 1; i <= M-2; i++) {
		for (j = i + 1; j <= M-1; j++) {
			for (k = j + 1; k <= M; k++) {
														//cout << i << " " << j << " " << k << endl;
				//원본 카피
				//for (l = 1; l <= M; l++) v2[l] = v[l];
				for (int it1 =1 ; it1 <= N; it1++) {
					for (int it2 = 1; it2 <= M; it2++) {
						arr2[it1][it2] = arr[it1][it2];
					}
				}

				
				pos[0] = i;
				pos[1] = j;
				pos[2] = k;
				int level = -1, sum = 0;
				

				//적 없을때까지 반복
				for(level=0;level<=N;level++) {
					//조준 대상 탐색
					vector <pair<int, int>> target;
					vector<pair<int, int>>::iterator iter;
					for (int i = 0; i < 3; i++) {
						Detect(D, target, pos[i], level);
					}
					
					for (iter = target.begin(); iter < target.end(); iter++) {
						int cy = iter->first, cx = iter->second;
																//cout << cy << " " << cx << endl;
						if (arr2[cy][cx]) { sum++; arr2[cy][cx] = 0; }
					}
					if (max < sum) max = sum;
															//cout <<"sum : " <<  sum << endl;
				}
				
			}
		}
	}
	cout << max << endl;

}