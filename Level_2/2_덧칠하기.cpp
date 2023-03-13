#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
	int answer = 0;

	auto index = 0;
	while (index < section.size())
	{
		int temp = 1;
		while (index + temp != section.size())
		{
			if (m > section[index + temp] - section[index])
				++temp;

			else
				break;
		}

		answer++;
		index += temp;
	}

	return answer;
}