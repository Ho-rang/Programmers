#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> clear;
	vector<float> fail_rate;
	vector<float> fail_rate2;

	int users = stages.size(); 
	for (int i = 0; i < N; i++) {
		clear.push_back(0);
		fail_rate.push_back(0);
		answer.push_back(0);
	}clear.push_back(0);

	for (int i = 0; i < stages.size(); i++)
		clear[stages[i]-1]++;
	
	for (int i = 0; i < fail_rate.size(); i++) {
		if (clear[i] != 0)
			fail_rate[i] = (float)clear[i] / users;
		
		users -= clear[i];
		if (users < 1)
			break;
	}
	fail_rate2 = fail_rate;
	
	sort(fail_rate.begin(), fail_rate.end());
	reverse(fail_rate.begin(), fail_rate.end());

	for (int i = 0; i < fail_rate.size(); i++) {
		for (int j = 0; j < fail_rate2.size(); j++) {
			if (fail_rate[i] == fail_rate2[j]) {
				answer[i]=(j + 1);
				fail_rate2[j] = 1;
				break;
			}
		}
	}

	return answer;
}
