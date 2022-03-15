#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	int front = 0;
	int end = people.size() - 1;

	while (true)
	{
		if (front > end)
			break;

		if (people[front] + people[end] <= limit)
			front++;
		end--;
		answer++;
	}

	return answer;
}