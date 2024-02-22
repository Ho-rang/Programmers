#include <vector>

class Solution
{
public:
	int findJudge(int n, std::vector<std::vector<int>>& trust)
	{
		int result = -1;

		std::vector<std::vector<int>> person(n, std::vector<int>(2));

		for (auto& t : trust)
		{
			person[t[0] - 1][0]++;
			person[t[1] - 1][1]++;
		}

		int cnt = 1;
		for (auto& p : person)
		{
			if (p[0] == 0 && p[1] == n - 1)
			{
				if (result != -1)
					return -1;

				result = cnt;
			}
			cnt++;
		}

		return result;
	}
};