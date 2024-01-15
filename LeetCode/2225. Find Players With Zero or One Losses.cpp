#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
	std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
	{
		std::vector<std::vector<int>> result(2);

		std::unordered_map<int, int> loseCount;

		for (const auto& match : matches)
		{
			loseCount[match[0]];
			loseCount[match[1]]++;
		}

		for (const auto& lose : loseCount)
		{
			if (lose.second == 0)
				result[0].push_back(lose.first);
			else if (lose.second == 1)
				result[1].push_back(lose.first);
		}

		std::sort(result[0].begin(), result[0].end());
		std::sort(result[1].begin(), result[1].end());

		return result;
	}
};