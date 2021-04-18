#include<iostream>
#include<vector>

using namespace std;
vector<int> v[2][10];
int value[10] = { 0, };
void swap(int *a, int *b) { int tmp = *a; *a = *b; *b = tmp; }
int gcd(int a, int b) {
	int c = 0;
	if (b > a) swap(a, b);
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcd(int a, int b) { return a * b / gcd(a, b);
}
void prop(int n, int coef, int prev) {
		value[n] *= coef;
		for (int status = 0; status < 2; status++) {
			for (int i = 0; i < v[status][n].size(); i++) {
				if (v[status][n].at(i) == prev)continue;
				prop(v[status][n].at(i), coef, n);
			}
		}
}
int main() {
	freopen("input.txt", "r", stdin);
	int a, b, p, q, n;
	int i, j, ret;
	cin >> n;
	for (i = 0; i < n; i++) value[i] = 1;
	for (int j = 0; j < n - 1; j++) {
		int lcdv, gcdv;
		cin >> a >> b >> p >> q;

		gcdv = gcd(value[a] * q, value[b] * p);

		int left = value[b] * p/gcdv;
		int right = value[a] * q/gcdv;	

		prop(a, left  , -1);
		prop(b, right , -1);


		v[0][a].push_back(b);
		v[1][b].push_back(a);
	}
		for (i = 0; i < n; i++) cout << value[i] << " ";
}
