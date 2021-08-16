#include <iostream>
#include <vector>
using namespace std;
/*
* N : 정수의 범위
* K : 정수의 개수
* DP[n][s] = n개의 수로 s를 만드는 경우의 수
*/
int N, K;
long long int DP[211][211] = { 0, };
//r : 사용한 수의 개수
//sum : r개의 수를 사용했을 때 남은 채워야할 수의 합
long long int f(int r, int sum) {
	long long int ret = 0, num = 0;
	
	if (r == K) {
		if (sum == 0) return 1;
		else return 0;
	}

	int i, j;
	for (i = 0; i <= sum; i++) {
		//방문한 적이 없는 경우
		if (DP[r + 1][sum - i] == -1) {
			num += (f(r + 1, sum - i) % (long long int)1e9);
		}
		//방문 했던 경우
		else num += (DP[r + 1][sum - i] % (long long int)1e9);
	}
	//탐색 결과를 저장
	DP[r][sum] = num;
	return num;
}
int main() {
	cin >> N >> K;
	int i, j;
	for (i = 0; i <= 200; i++) {
		for (j = 0; j <= 200; j++) {
			DP[i][j] = -1;
		}
	}
	cout << f(0, N) % (long long int)1e9 << endl;
	return 0;
}