#include <vector>
#include <algorithm>

class Solution
{
public:
	int minFallingPathSum(std::vector<std::vector<int>>& matrix)
	{
		int n = matrix.size();
		for (int i = 0; i < n - 1; i++)
		{
			int threeNum[3] = { 100,100,100 };
			int mod = 0;

			threeNum[mod++] = matrix[i][0];

			for (int j = 0; j < n - 1; j++)
			{
				threeNum[mod++ % 3] = matrix[i][j + 1];

				matrix[i + 1][j] += std::min(threeNum[0], std::min(threeNum[1], threeNum[2]));
			}

			matrix[i + 1][n - 1] += std::min(threeNum[(mod + 2) % 3], threeNum[(mod + 1) % 3]);
		}

		return *std::min_element(matrix.back().begin(), matrix.back().end());
	}
};

void main()
{
	Solution s;
	std::vector<std::vector<int>> v =
	{
		{17,82},
		{1,-44}, };
	s.minFallingPathSum(v);


}