#include <vector>

class Solution
{
public:
	std::vector<int> sortedSquares(std::vector<int>& nums)
	{
		std::vector<int> result(nums.size());

		int left = 0, right = nums.size() - 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (::abs(nums[left]) < ::abs(nums[right]))
			{
				result[i] = ::pow(nums[right], 2);
				right--;
			}
			else
			{
				result[i] = ::pow(nums[left], 2);
				left++;
			}
		}

		return result;
	}
};