#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<std::vector<int>> findMatrix(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> result;

		std::sort(nums.begin(), nums.end());

		result.resize(1);
		result[0].push_back(nums[0]);

		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] == nums[i])
			{
				index++;
				if (result.size() <= index)
					result.push_back(std::vector<int>());

				result[index].push_back(nums[i]);
			}
			else
			{
				index = 0;
				result[index].push_back(nums[i]);
			}
		}

		return result;
	}
};

void main()
{
	Solution s;
	std::vector<int> v = { 1,3,4,1,2,3,1 };
	s.findMatrix(v);
}