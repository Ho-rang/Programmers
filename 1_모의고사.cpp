#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<int> b = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> c = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	vector<int> right{ 0,0,0 };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == a[i % 5])
			right[0]++;

		if (answers[i] == b[i % 8])
			right[1]++;

		if (answers[i] == c[i % 10])
			right[2]++;

	}

	int m = 0;
	for (int i : right)
		m = max(m, i);

	for (int i = 0; i < 3; i++) 
		if (right[i] == m) 
			answer.push_back(i+1);
		
	return answer;
}
