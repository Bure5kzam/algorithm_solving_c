#include <iostream>
#include <vector>
using namespace std;
int N, L;
vector <int> v;
int main() {
	cin >> N >> L;

	for (int i = 1; i <= N; i++) v.push_back(i);

	cout << "<";
	int idx = -1;
	while (1) {
		idx = (idx + L) % N ;
		cout << v.at(idx);


		v.erase(v.begin() + idx, v.begin() + idx + 1);
		N--;idx--;

		if (N == 0) break;
		cout << ", ";
	}
	cout << ">" << endl;
}