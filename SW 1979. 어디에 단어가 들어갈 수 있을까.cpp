#include <iostream>
#include <string.h>
using namespace std;
int arr[20][20] = { 0, }, N, K, moor[2] = { 0, }, target[15] = { 0, };
char str[4] = "abc";
char str2[20] = "ccccccabc";
int table[5] = { 0,1,2 };
int check(int idx, int N) {
	int i;
	for(i=1;i<=N;i++) {
		if (str[N - i] != str2[idx + N - i]) return 0;
	}
	return 1;
}
int move() {
	int idx = 0;
	while (idx < strlen(str2)) {
		if (check(idx,strlen(str))) return idx;
		else {
			idx += strlen(str) - 1;
			idx -= table[str2[idx] - 'a'];
		}
	}
	return -1;
}

int main() {
	int i, j,idx;
	

	//cin >> N >> K;
	//moor[0] = 0;
	//moor[1] = N;
	//for (i = 0; i <= K + 1; i++) target[i] = (i == 0 || i == N + 1)? 0 : 1;
	//for (i = 0; i <= N + 1; i++) {
	//	for (j = 0; j <= N + 1; j++) {
	//		if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
	//			arr[i][j] = 0;
	//		}
	//		else cin >> arr[i][j];
	//	}
	//}

	//for (i = 0; i <= N + 1; i++) {
	//	idx = K;
	//	
	//}
	cout << move()<< endl;
}

/*
0 1 2 3 4 5 6 7 8
b c a b c a b c
c a b c a b c

a b c
0 1 2

apple napple

naple
01234
*/