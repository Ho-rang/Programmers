#include "pch.h"

class Solution
{
public:
	long long countSubarrays(vector<int>& nums, int k)
	{
		const int max = *ranges::max_element(nums);

		long long result = 0;

		for (int front = 0, end = 0, count = 0; end < nums.size(); end++)
		{
			if (nums[end] == max)
				++count;

			while (count >= k)
				if (nums[front++] == max)
					--count;

			result += front;
		}

		return result;
	}
};