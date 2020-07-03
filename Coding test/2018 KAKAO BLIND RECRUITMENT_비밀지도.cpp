#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> arr3;
	
	for (int i = 0; i < n; i++) {
		arr3.push_back(arr1[i] | arr2[i]);

		string word = "";

		for (int j = n - 1; j >= 0; j--) {

			int num = pow(2, j);

			if (arr3[i] >= num) {
				arr3[i] -= num;
				word += '#';
			}
			else {
				word += ' ';
			}
		}
		
		answer.push_back(word);
	}
    return answer;
}
