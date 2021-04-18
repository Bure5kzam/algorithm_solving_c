#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
char cond[11] = { 0, };
string cmx="-1", cmn="999999999", arr = "0123456789";
void swap(char * a, char * b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void p(int n) {
	int i, j;
	if (n == N+1) {
		/*for (i = 0; i < n; i++) cout << arr[i] << " ";
		cout << endl;*/

		if (cmn.compare(arr) > 0) cmn = arr;
		if (cmx.compare(arr) < 0) cmx = arr;
		return;
	}
	for (i = n ; i <= 9; i++) {
		
		if (n > 0) {
			if (cond[n] == '<' && arr[n - 1] > arr[i]) continue;
			if (cond[n] == '>' && arr[n - 1] < arr[i]) continue;
		}
		
		swap(arr[n], arr[i]);
		p(n + 1);
		swap(arr[i], arr[n]);

	}

}
int main() {
	int n, i, j;
	cin >> N;
	for (i = 1; i <= N; i++) cin >> cond[i];
	p(0);
	cout << cmx.substr(0, N+1) << "\n" << cmn.substr(0, N+1) << endl;
	
}