#include <string>
#include <vector>

using namespace std;

    vector<string> day = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
	vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31 };

string solution(int a, int b) {
    string answer = "";
    
	for (int i = 0; i < a - 1; i++) {
		b += month[i];
	}

	answer = day[b % 7];
    return answer;
}
