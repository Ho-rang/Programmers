#include <vector>
using std::vector;



#include <algorithm>

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		auto start = std::find(nums.begin(), nums.end(), target);

		if (start == nums.end())
			return { -1,-1 };

		auto end = std::find(nums.rbegin(), nums.rend(), target);

		return { (int)std::distance(nums.begin(), start), (int)std::distance(nums.begin(), end.base()) - 1 };
	}
};