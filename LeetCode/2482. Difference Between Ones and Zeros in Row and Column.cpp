#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid)
	{
		std::vector<int> row(grid[0].size());
		std::vector<int> col(grid.size());

		std::vector<std::vector<int>> diff(grid.size(), std::vector<int>(grid[0].size(), 0));

		for (int c = 0; c < grid.size(); c++)
		{
			for (int r = 0; r < grid[0].size(); r++)
			{
				if (grid[c][r] == 1)
				{
					row[r]++;
					col[c]++;
				}
				else
				{
					row[r]--;
					col[c]--;
				}
			}
		}

		for (int c = 0; c < grid.size(); c++)
		{
			for (int r = 0; r < grid[0].size(); r++)
			{
				diff[c][r] = row[r] + col[c];
			}
		}

		return diff;
	}
};