#include <vector>
#include <numeric>

class Solution {
public:
	int missingNumber(std::vector<int>& nums)
	{
		return (nums.size() * (nums.size() + 1)) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
	}
};