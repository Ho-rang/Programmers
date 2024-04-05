#include "pch.h"

class Solution
{
public:
	int maxSubarrayLength(vector<int>& nums, int k)
	{
		int result = 0;

		unordered_map<int, int> numCount;

		int front = 0;
		int end = 0;

		while (end < nums.size())
		{
			++numCount[nums[end]];

			if (numCount[nums[end]] <= k)
			{
				result = std::max(result, end - front + 1);
			}
			else
			{
				while (nums[end] != nums[front])
					numCount[nums[front++]]--;

				numCount[nums[front++]]--;

				result = std::max(result, end - front + 1);
			}

			end++;
		}

		return result;
	}
};