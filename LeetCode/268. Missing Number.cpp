#include <string>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>

class Solution {
public:
	int missingNumber(std::vector<int>& nums)
	{
		int result{ static_cast<int>((nums.size() * (nums.size() + 1)) / 2) };

		result -= std::accumulate(nums.begin(), nums.end(), 0);

		return result;
	}
};