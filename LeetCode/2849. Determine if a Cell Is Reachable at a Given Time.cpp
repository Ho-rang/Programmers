#include <algorithm>

class Solution
{
public:
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
	{
		int dx = std::abs(sx - fx);
		int dy = std::abs(sy - fy);

		int minTime = dx > dy ? dx : dy;

		if (t == 1 && minTime == 0)
			return false;

		return t >= minTime;
	}
};