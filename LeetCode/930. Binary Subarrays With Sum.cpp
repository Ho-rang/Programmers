#include "pch.h"

class Solution
{
public:
	int numSubarraysWithSum(vector<int>& nums, int goal)
	{
		int result = 0;

		{
			int count = 0;
			int sum = 0;

			int end = 0;
			for (int start = 0; start < nums.size(); start++)
			{
				sum += nums[start];

				while (sum > goal)
					sum -= nums[end++];

				count += start - end + 1;
			}

			result += count;
		}
		{
			if(--goal < 0)
				return result;

			int count = 0;
			int sum = 0;

			int end = 0;
			for (int start = 0; start < nums.size(); start++)
			{
				sum += nums[start];

				while (sum > goal)
					sum -= nums[end++];

				count += start - end + 1;
			}

			result -= count;
		}

		return result;
	}
};