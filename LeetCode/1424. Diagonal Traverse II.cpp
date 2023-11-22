#include <vector>

class Solution
{
public:
	std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums)
	{
		std::vector<std::vector<int>> temp;
		
		int totalCount = 0;
		int maxSize = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			totalCount += nums[i].size();
			for (int j = 0; j < nums[i].size(); j++)
			{
				if (temp.size() < i + j + 1)
					temp.resize(i + j + 1);

				temp[i + j].push_back(nums[i][j]);
				maxSize = std::max(maxSize, i + j);
			}
		}


		std::vector<int> result(totalCount);
		int index = 0;

		for (int i = 0; i <= maxSize; i++)
		{
			for (int j = temp[i].size() - 1; j >= 0; j--)
			{
				result[index++] = temp[i][j];
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> nums = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	s.findDiagonalOrder(nums);
}