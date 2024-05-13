#include <vector>

using namespace std;

class Solution
{
public:
	int matrixScore(vector<vector<int>>& grid)
	{
		for (auto& row : grid)
		{
			if (row[0] == 0)
				for (auto& cell : row)
					cell = 1 - cell;
		}

		int result = 0;

		for (int i = 0; i < grid[0].size(); i++)
		{
			int count = 0;
			for (int j = 0; j < grid.size(); j++)
				count += grid[j][i];

			result += max(count, (int)grid.size() - count) * (1 << (grid[0].size() - i - 1));
		}

		return result;
	}
};