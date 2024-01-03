#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
	int numberOfBeams(std::vector<std::string>& bank)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int result = 0;

		short prevCount = 0;
		for (size_t i = 0; i < bank.size(); i++)
		{
			short nowCount = std::count(bank[i].begin(), bank[i].end(), '1');

			if (nowCount != 0)
			{
				result += prevCount * nowCount;
				prevCount = nowCount;
			}
		}

		return result;
	}
};