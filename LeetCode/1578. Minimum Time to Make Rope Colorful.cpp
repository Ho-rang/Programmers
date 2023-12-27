#include <vector>
#include <string>

class Solution
{
public:
	int minCost(std::string colors, std::vector<int>& neededTime)
	{
		int result = 0;

		int maxCost = neededTime[0];
		int cost = neededTime[0];

		for (int i = 1; i < colors.length() - 1; i++)
		{
			if (colors[i - 1] != colors[i])
			{
				result += cost - maxCost;
				cost = neededTime[i];
				maxCost = neededTime[i];
			}
			else
			{
				cost += neededTime[i];
				maxCost = std::max(maxCost, neededTime[i]);
			}
		}

		if (colors[colors.length() - 2] == colors[colors.length() - 1])
		{
			result += cost - maxCost;
		}

		return result;
	}
};