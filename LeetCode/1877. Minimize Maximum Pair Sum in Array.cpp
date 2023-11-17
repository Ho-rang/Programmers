#include <vector>
#include <algorithm>

class Solution
{
public:
	int minPairSum(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());

		int result = 0;
		for (int i = 0; i < nums.size() / 2; i++)
		{
			result = std::max(result, nums[i] + nums[nums.size() - i - 1]);
		}
		return result;
	}
};