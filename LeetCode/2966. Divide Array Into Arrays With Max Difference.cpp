#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k)
	{
		std::sort(nums.begin(), nums.end());

		int n = nums.size();

		std::vector<std::vector<int>> result(n / 3, std::vector<int>(1));

		for (int i = 0; i < n; i += 3)
		{
			if (nums[i] + k < nums[i + 2])
				return std::vector<std::vector<int>>();

			result[i/3] = { nums[i] ,nums[i + 1] ,nums[i + 2] };
		}

		return result;
	}
};