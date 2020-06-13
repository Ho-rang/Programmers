#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;

	int num = x;
	int digit = 0;

	while (1) {
		if (num == 0)
			break;

		digit += num % 10;
		num /= 10;
	}
	
	answer = x % digit != 0 ? false : true;
	return answer;
}
