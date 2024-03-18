#include "pch.h"

class Solution
{
public:
	int findMinArrowShots(vector<vector<int>>& points)
	{
		int result = 1;

		ranges::sort(points, [](const auto& a, const auto& b)
			{ return a[0] < b[0]; });

		int end = points[0][1];
		for (int i = 1; i < points.size(); i++)
		{
			if (end < points[i][0])
			{
				result++;
				end = points[i][1];
			}
			else
			{
				end = std::min(end, points[i][1]);
			}
		}

		return result;
	}
};