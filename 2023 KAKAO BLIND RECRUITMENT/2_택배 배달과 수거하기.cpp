#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
	long long answer = 0;


	while (!deliveries.empty() || !pickups.empty())
	{
		int distance = 0;

		bool flag1 = false;
		int box1 = 0;
		while (!deliveries.empty())
		{

			auto& deliver = deliveries[deliveries.size() - 1];

			if (deliver == 0)
			{
				deliveries.pop_back();
				continue;
			}

			if (!flag1)
			{
				flag1 = true;
				answer += deliveries.size();
				distance = deliveries.size();
			}

			if (deliver + box1 <= cap)
			{
				box1 += deliver;
				deliver = 0;
			}
			else
			{
				deliver -= cap - box1;
				box1 = cap;
			}

			if (box1 == cap)
				break;
		}

		bool flag2 = false;
		int box2 = 0;
		while (!pickups.empty())
		{

			auto& pick = pickups[pickups.size() - 1];

			if (pick == 0)
			{
				pickups.pop_back();
				continue;
			}

			if (!flag2)
			{
				flag2 = true;

				if (distance < pickups.size())
				{
					answer += pickups.size() - distance;
				}
			}

			if (pick + box2 <= cap)
			{
				box2 += pick;
				pick = 0;
			}
			else
			{
				pick -= cap - box2;
				box2 = cap;
			}

			if (box2 == cap)
				break;
		}
	}

	return answer * 2;
}