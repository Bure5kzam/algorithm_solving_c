#include <iostream>
#include <vector>

using namespace std;
vector <int> v;
int target, num=0;
void func(int n,int mx, int limit) {
	int i, j;
	if (n == mx) {
		if (num++ == target) {
			for (i = 0; i <v.size(); i++) {
				cout << v.at(i);
			}
			cout << endl;
			
		}
		return;
	}

	for (i = 0; i <= limit; i++) {
		v.push_back(i);
		func(n + 1, mx, i - 1);
		v.pop_back();
	}

}
int main() {
	int cnt = 0, i, j;
	cin >> target;
	if (target > 1022 || target < 0) {
		cout << -1 << endl; return 0;
	}
	


	int arr[2][12] = { 0, };
	arr[0][1] = 1;

	for (i = 1; i <= 11; i++) {
		for (j = 1; j < i + 1; j++) {
			arr[i % 2][j] = arr[(i + 1) % 2][j - 1] + arr[(i + 1) % 2][j];
		}
	}
	//1 10 45 120 210 252 210 120 45 10 1


	int sum = -1, prev = -1;
	for (i = 2; i <= 11; i++) {
		sum += arr[1][i];
		if (sum >= target) break;
		prev = sum;
	}

	num = prev+1;
	func(0, --i, 9);
}