#include <iostream>
#include <sstream>
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
				hashk += (mask &( 1 << j)) ? "-" : k[j];
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
		cout << value << endl;
		string queryk = q[0] + q[1] + q[2] + q[3];
		for (auto& e : hh[queryk]) {
			if (e >= value) sum++;
		}
		answer.push_back(sum);
	}
	
	return answer;
}
int main() {
	vector<string> v1{ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> v2{ "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	solution(v1, v2);
}