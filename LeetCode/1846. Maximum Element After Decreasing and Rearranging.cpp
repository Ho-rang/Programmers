#include <vector>
#include <algorithm>

class Solution
{
public:
	int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr)
	{
		std::sort(arr.begin(), arr.end());

		int count = std::distance(arr.begin(), std::unique(arr.begin(), arr.end()));

		int num = 1;
		for (int i = 1; i < count; i++)
		{
			if (arr[i] - num > 0)
			{
				++num;
			}
		}

		return num;
	}
};