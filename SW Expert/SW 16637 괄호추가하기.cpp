/*
* 1. 문제 분석
* 트리를 이용하는 문제인가 했지만
* 1. 연산자의 우선순위가 없다
* 2. 괄호안에 하나의 연산자만 들어있다.
* 3. 0~9까지 하나의 문자만 준다
* 이를 봤을때 배열에 넣고 처리하라는 문제인 것 같다.
* 
* N의 범위가 20인걸 봐서 완전탐색을 수행해도 될 것 같다.
*/
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;
int N, ans=-1e9;
int Calc2(int a, int b, char* o) {
	int result = 0;
	switch (*o) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}
	return result;
}
void Calc(vector<int>& n, string& o) {
	int result = n.at(0);
	for (int i = 0; i < o.length(); i++) result = Calc2(result, n.at(i+1), &o[i]);
	if (ans < result) ans = result;
}
void makeStr(vector<int> &n, string &o, int idx) {
	vector<int> n2=n, n3 = n;
	string o2 = o, o3 = o;
	int result = 0;
	if (idx >= o.length()) {
		//cout << n << endl << o << endl << endl;
		Calc(n, o);
		return;
	}
	result = Calc2(n2[idx], n2[idx + 1], &o2[idx]);
	n2.erase(n2.begin()+idx);
	o2.erase(idx,1);
	n2[idx] = result;
	makeStr(n2, o2, idx+1);
	makeStr(n3, o3, idx + 1);

}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j;
	cin >> N;
	string s, ops;
	vector <int> nums;
	cin.ignore();
	getline(cin, s);
	for (i = 0; i < s.length(); i += 2) {
		nums.push_back(s[i]-'0');
		if (i + 2 < s.length()) ops.push_back(s[i + 1]);
	}

	makeStr(nums, ops,0);
	cout << ans << endl;
}