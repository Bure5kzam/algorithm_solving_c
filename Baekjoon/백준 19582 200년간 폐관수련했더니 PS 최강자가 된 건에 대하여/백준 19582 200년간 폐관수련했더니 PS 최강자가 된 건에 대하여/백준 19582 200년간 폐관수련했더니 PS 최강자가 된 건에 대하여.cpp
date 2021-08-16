#include <iostream>
using namespace std;
/*
* ARR : 대회 참여 제한 점수와 점수 입력받는 변수
* DP[0] : 이전 대회 참여 이력
* DP[1] : 현재 대회 참여 결과
*/
int N, ARR[111111][2] = { 0, };
long long int DP[2][2] = { 0, };
int main() {
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 0; j < 2; j++)cin >> ARR[i][j];
	}
	//cout << endl;
	for (i = 1; i <= N; i++) {
		int limit = ARR[i][0];
		int score = ARR[i][1];

		//1-1 대회를 다 참여한 경우
		DP[1][0] = (DP[0][0] <= limit) ? DP[0][0] + score : 1e16;

		//2-1 대회를 다 참여하지 않은 경우

		long long int ret1 = 0, ret2 = 0;
		//2-2-1 이전 대회를 다 참여하고 이번에 참여하지 않는 경우
		ret1 = (DP[0][0]) ? DP[0][0]: 1e16;

		//2-2-2 이미 이전에 한번 대회를 참여하지 않은 경우
		ret2 = (DP[0][1] <= limit) ? DP[0][1] + score : 1e16;
		DP[1][1] = (ret1 < ret2) ? ret1 : ret2;

		if (DP[1][0] == 1e16 && DP[1][1] == 1e16) {
			cout << "Zzz" << "\n";
			return 0;
		}

		DP[0][0] = DP[1][0];
		DP[0][1] = DP[1][1];
		cout << DP[0][0] << " " << DP[0][1] << " " << ret1 <<" " <<  ret2 <<  "\n";
	}
	cout << "Kkeo-eok" << "\n";
}