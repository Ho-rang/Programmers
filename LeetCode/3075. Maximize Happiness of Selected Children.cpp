#include "pch.h"

class Solution
{
public:
	long long maximumHappinessSum(vector<int>& happiness, int k)
	{
		std::ranges::sort(happiness, std::greater<int>());

		long long result = 0;

		int count = 0;

		for (int i = 0; i < k; i++)
		{
			auto sub = happiness[i] - count;

			if (sub < 1)
				break;

			result += sub;
			count++;
		}

		return result;
	}
};