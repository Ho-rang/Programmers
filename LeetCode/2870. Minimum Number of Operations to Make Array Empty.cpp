#include <vector>
#include <unordered_map>

class Solution
{
public:
	int minOperations(std::vector<int>& nums)
	{
		int result = 0;

		std::unordered_map<int, int> numCount;

		for (const auto& num : nums)
			numCount[num]++;

		for (const auto& pair : numCount)
		{
			if (pair.second == 1)
				return -1;

			if (pair.second % 3 != 0)
				result++;

			result += pair.second / 3;
		}

		return result;
	}
};