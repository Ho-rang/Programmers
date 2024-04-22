#include <vector>

using namespace std;

class Solution
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		int result = 0;

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					result++;
					Dfs(i, j, grid);
				}
			}
		}

		return result;
	}

public:
	void Dfs(int y, int x, vector<vector<char>>& grid)
	{
		constexpr static int dy[] = { 1, -1, 0, 0 };
		constexpr static int dx[] = { 0, 0, 1, -1 };

		grid[y][x] = '0';

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= grid.size() ||
				nx < 0 || nx >= grid[0].size() ||
				grid[ny][nx] == '0')
				continue;

			Dfs(ny, nx, grid);
		}
	}
};