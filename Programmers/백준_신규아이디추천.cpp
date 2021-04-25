#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;
string solution(string new_id) {
	string answer = new_id, cvt = "";
	cout << "0 / " << answer << endl;

	cvt = "";
	for (auto& i : new_id)cvt += (isupper(i)) ? i + ('a' - 'A') : i;
	answer = cvt;
	cout << "1 / " << answer << endl;



	cvt = "";
	for (auto&i : answer) cvt += (isdigit(i) || isalpha(i) || i == '-' || i == '_' || i == '.') ? i : NULL;
	answer = cvt;
	cout << "2 / " << answer << endl;

	cvt = "";
	for (int i = 0; i < answer.size(); i++) cvt += (i == 0 || (answer[i - 1] != '.' || answer[i] != '.')) ? (answer[i]) : NULL;
	answer = cvt;
	cout << "3 / " << answer << endl;

	if (*(answer.begin()) == '.') answer.erase(answer.begin());
	if (*(answer.end() - 1) == '.') answer.erase(answer.end() - 1);
	cout << "4 / " << answer << endl;

	if (answer.empty())answer = "a";
	cout << "5 / " << answer << endl;

	answer = answer.substr(0, 15);
	if (*(answer.end() - 1) == '.') answer.pop_back();
	cout << "6 / " << answer << endl;

	if (answer.size() <= 2) {
		int idx = answer.size();
		for (int i = idx; i <= 3; i++) {
			answer += *(answer.begin() + idx - 1);
		}
	}
	cout << "7 / " << answer << endl;

	return answer;

}
int main() {
	solution("...!@BaT#*..y.abcdefghijklm.");
}