#include "pch.h"

class Solution
{
public:
	int maxFrequencyElements(vector<int>& nums)
	{
		std::unordered_map<int, int> numCount;

		int maxCount = 0;
		int maxNumCount = 0;

		for (int i{ 0 }; i < nums.size(); i++)
		{
			auto& num = ++numCount[nums[i]];

			if (maxCount < num)
			{
				maxCount = num;
				maxNumCount = 1;
			}
			else if (maxCount == num)
			{
				maxNumCount++;
			}
		}

		return maxCount * maxNumCount;
	}
};