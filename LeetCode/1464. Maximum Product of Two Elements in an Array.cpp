#include <vector>
#include <algorithm>

class Solution
{
public:
	int maxProduct(std::vector<int>& nums)
	{
		int a = 0;
		int b = 0;

		for (const auto num : nums)
		{
			if (a < num)
			{
				a = num;
				if (a > b)
					std::swap(a, b);
			}
		}

		return (a - 1) * (b - 1);
	}
};