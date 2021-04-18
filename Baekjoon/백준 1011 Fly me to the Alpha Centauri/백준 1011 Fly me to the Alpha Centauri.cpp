#include <iostream>
using namespace std;
int S, E, cnt=-1;
void f(int s, int d, int ld, int lc) {
	/*
	s : 현재속도
	d : 남은 거리
	ld : 현재 속도에서 감속해서 도착할 수 있는 최소 거리
	lc : 현재 속도에서 감속해서 ld만큼 가는데 필요한 횟수
	*/

	cnt++;

	//cout << s << " " << d << " " << ld << " " << lc << endl;
	if (ld == d) {
		cnt += lc;
		return;
	}
	if (ld + s <=d - (s+1)) {
		//속도 증가
		f(s + 1, d - (s + 1), ld + s, (ld+s!=0)?(lc+1):lc);
	}
	else if (ld <= d - s) {
		//속도 유지
		f(s, d - s, ld, lc);
	}
	else {
		//속도 감소
		f(s - 1, d - s + 1, ld - s+1, (ld!=0) ? lc-1 : lc);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cnt = -1;
		cin >> S >> E;
		f(0, E - S, 0, 0);
		cout << cnt << endl;
	}
}