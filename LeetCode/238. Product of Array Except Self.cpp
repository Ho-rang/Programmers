#include "pch.h"

class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		vector<int> result(nums.size(), 1);

		{
			int mul = 1;
			for (int i{ 0 }; i < nums.size(); i++)
			{
				result[i] = mul;
				mul *= nums[i];
			}
		}
		{
			int mul = 1;
			for (int i = nums.size() - 1; i >= 0; i--)
			{
				result[i] *= mul;
				mul *= nums[i];
			}
		}

		return result;
	}
};