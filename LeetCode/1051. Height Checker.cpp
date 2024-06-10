#include "pch.h"

class Solution
{
public:
	int heightChecker(vector<int>& heights)
	{
		int result = 0;

		vector<int> sortedHeights = heights;
		std::sort(sortedHeights.begin(), sortedHeights.end());

		for (int i = 0; i < heights.size(); i++)
			if (heights[i] != sortedHeights[i])
				result++;

		return result;
	}
};