#include <string>

using namespace std;

int solution(string dartResult) {
    
	int answer = 0;
	int num[3] = { 0, };
	int index = 0;

	for (int i = 0; i < dartResult.size(); i++) {


		if (dartResult[i] <= '*') {
			if (dartResult[i] == '*') {
				num[index - 1] *= 2;
				if (index != 1)
					num[index - 2] *= 2;
			}
			else {
				num[index - 1] *= -1;
			}
		}
		else if ('D' <= dartResult[i]) {
			if (dartResult[i] == 'D')
				num[index] = num[index] * num[index];
			else if (dartResult[i] == 'T')
				num[index] = num[index] * num[index] * num[index];

			index++;
		}
		else {
			if (dartResult[i] == '1') {
				if (dartResult[i + 1] == '0') {
					num[index] = 10;
					i++;
				}
				else {
					num[index] = 1;
				}
			}
			else {
				num[index] = (int)dartResult[i] - '0';
			}
		}

	}

	answer = num[0] + num[1] + num[2];

    return answer;
}
