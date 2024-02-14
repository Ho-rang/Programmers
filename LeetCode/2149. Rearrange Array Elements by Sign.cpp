#include <vector>
#include <queue>
#include <ranges>

class Solution
{
public:
	std::vector<int> rearrangeArray(std::vector<int>& nums)
	{
		std::vector<int> result(nums.size());

		int positiveNum = 0;
		int negativeNum = 1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				result[positiveNum] = nums[i];
				positiveNum += 2;
			}
			else
			{
				result[negativeNum] = nums[i];
				negativeNum += 2;
			}
		};

		return result;
	}
};