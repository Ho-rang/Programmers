#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int answer = 0;
	double d_num = num;

	while (1) {
		if (d_num == 1) {
			break;
		}
		else if (answer >= 500) {
			answer = -1;
			break;
		}

		d_num = (int)d_num & 1 ? (d_num * 3) + 1 : d_num / 2;
		answer++;

	}
	return answer;
}
