#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> order)
{
	int answer = 0;

	std::vector<int> conveyor(order.size() + 1);
	std::iota(conveyor.begin(), conveyor.end(), 1);

	int targetBox = 1;

	for (int i = 0; i < order.size(); i++)
	{
		if (targetBox <= order[i])
		{
			targetBox = order[i];
			conveyor[targetBox] = 0;
			answer++;
			continue;
		}
		else
		{
			while (conveyor[--targetBox] == 0) {}

			if (targetBox == order[i])
			{
				conveyor[targetBox] = 0;
				answer++;
				continue;
			}
			else
			{
				break;
			}

		}



	}

	return answer;
}