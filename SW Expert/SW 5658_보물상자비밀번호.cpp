#include <iostream>
#include <algorithm>
using namespace std;
char str[30] = { 0, };
int stack[30], top = 0;
int N, K;
int com(const void * a,const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2) return -1;
	
	else if(num2 > num1) return 1;
	return 0;
}
int main() {
	int i, j, dec, tc, t;
	bool isEx = false;
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (tc = 1; tc <= t; tc++) {

		cin >> N >> K;
		cin >> str;
		for (i = 0; i < N; i++) {
			dec = 0;
			isEx = false;
			for (j = 0; j < N / 4; j++) {
				dec *= 16;
				char curC = str[(i + j) % N];
				if (curC > '9') dec += curC - 'A' + 10;
				else dec += curC - '0';
			}
			for (j = 0; j < top; j++) {
				if (dec == stack[j]) { isEx = true; break; }
			}
			if (!isEx) stack[top++] = dec;
		}
		qsort(stack, top, sizeof(int), com);
		cout << "#" << tc << " " << stack[K - 1] << endl;
		for (i = 0; i < 30; i++) stack[i] = 0;
		top = 0;
	}
}