#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[100] = { 0, };
int main() {
	int i, j,tg;
	cin >> N;
	
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	//Á¤·Ä
	sort(arr, arr + N);


	cin >> tg;
	int st=0, end = 0, cnt=0;
	while (tg > arr[st]) { st++; }
	st--;


	end = arr[st + 1]-1;
	st = arr[st]+1;

	for (i = st; i <= tg; i++) {
		for (j = tg; j <= end; j++) {
			if (i != j) {
				//cout << i << " to " << j << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

/*
4
1 7 14 10
2
*/