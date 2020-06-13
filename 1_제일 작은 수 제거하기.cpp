#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	if (arr.size() <= 1) {
		answer.push_back(-1);
		return answer;
	}

	int num = arr[0];
	for (int i = 1; i < arr.size();i++) {
		num = min(num, arr[i]);
	}
	vector<int>::iterator iter = find(arr.begin(), arr.end(), num);

	for (int i = 0; i < arr.size();i++) {
		if (num == arr[i]) {
			arr.erase(iter);
		}
	}
	answer = arr;
	return answer;
}
