#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	if (a > b) {
		swap(a, b);
	}

	long long answer = b;

	for (int i = 0; i < b - a; i++) {
		answer += a + i;
	}
	return answer;
}
