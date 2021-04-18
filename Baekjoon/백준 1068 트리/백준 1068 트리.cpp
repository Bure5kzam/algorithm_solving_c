#include <iostream>
using namespace std;
int N, tree1[50] = { 0, }, tree2[50][50] = { 0, }, cnt=0;
void f(int n) {
	for (int i = 1; i <= tree2[n][0]; i++) {
		f(tree2[n][i]);
	}
	tree2[n][0] = -1;
}
int main()
{
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tree1[i] = tmp;
		tree2[tmp][++tree2[tmp][0]] = i;
	}
	cin >> tmp;
	int par = tree1[tmp];

	
	f(tmp);
	if (par != -1)tree2[par][0]--;
	for (int i = 0; i < N; i++) if (tree2[i][0] == 0) cnt++;
	cout << cnt << endl;

	
}