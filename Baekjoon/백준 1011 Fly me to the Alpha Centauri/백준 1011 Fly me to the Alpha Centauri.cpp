#include <iostream>
using namespace std;
int S, E, cnt=-1;
void f(int s, int d, int ld, int lc) {
	/*
	s : ����ӵ�
	d : ���� �Ÿ�
	ld : ���� �ӵ����� �����ؼ� ������ �� �ִ� �ּ� �Ÿ�
	lc : ���� �ӵ����� �����ؼ� ld��ŭ ���µ� �ʿ��� Ƚ��
	*/

	cnt++;

	//cout << s << " " << d << " " << ld << " " << lc << endl;
	if (ld == d) {
		cnt += lc;
		return;
	}
	if (ld + s <=d - (s+1)) {
		//�ӵ� ����
		f(s + 1, d - (s + 1), ld + s, (ld+s!=0)?(lc+1):lc);
	}
	else if (ld <= d - s) {
		//�ӵ� ����
		f(s, d - s, ld, lc);
	}
	else {
		//�ӵ� ����
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