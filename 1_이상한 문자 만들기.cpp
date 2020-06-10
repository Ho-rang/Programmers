#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;
	int check = 0;

	for (int i = 0; i < answer.size(); i++,check++){
		if (answer[i] == ' ') {
			check = 1;
		}
		else {
			check & 1 ? answer[i] = tolower(answer[i]) : answer[i] = toupper(answer[i]);
		}
	}
    
    return answer;
}
