#include "pch.h"
// ios::sync_with_stdio(false);

class Solution
{
public:
	long long largestPerimeter(vector<int>& nums)
	{
		ranges::sort(nums, std::greater<int>());

		long long result{ std::accumulate(nums.begin(),nums.end(), static_cast<long long>(0)) };
		
		int i{ 0 };
		for (; i < nums.size(); i++)
		{
			long long num = nums[i];
			if (result <= num * 2)
				result -= num;
			else
				break;
		}

		if (nums.size() - i < 3)
			return -1;

		return result;
	}
};