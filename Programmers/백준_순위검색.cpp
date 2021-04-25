#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, vector<int>> hh;
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	string k[4]; int value;
	for (auto& inf : info) {
		istringstream iss(inf);
		iss >> k[0] >> k[1] >> k[2] >> k[3] >> value;

		for (int mask = 0; mask < 16; mask++) {
			string hashk;
			for (int j = 0; j < 4; j++) {
				hashk += (mask &(1 << j)) ? "-" : k[j];
			}
			hh[hashk].push_back(value);
		}
	}

	//parsing query
	string q[4], tmp;
	for (auto&quer : query) {
		int value = 0, sum = 0;
		istringstream iss(quer);
		iss >> q[0] >> tmp >> q[1] >> tmp >> q[2] >> tmp >> q[3] >> value;
		// cout << value << endl;
		string queryk = q[0] + q[1] + q[2] + q[3];
		for (auto& e : hh[queryk]) {
			if (e >= value) sum++;
		}
		answer.push_back(sum);
	}

	return answer;
}

int main() {
	istringstream iss("java and backend and junior and pizza 100");
	string s[4];
	string f;
	while(getline(iss, f," " )) {
	}
	iss >> s[0] >> s[1] >> s[2] >> s[3];
	cout << s[0] << s[1] << s[2] << s[3];
}