#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int maxMoves(vector<vector<int>>& grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		int ans = 0;

		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++)
			q.push({ i, 0 });

		while (!q.empty())
		{
			auto [i, j] = q.front();
			q.pop();

			for (int k = -1; k <= 1; k++)
			{
				int ni = i + k;
				int nj = j + 1;

				if (ni < 0 || ni >= n || nj < 0 || nj >= m)
					continue;

				if (dp[ni][nj] != 0)
					continue;

				if (grid[i][j] < grid[ni][nj])
				{
					dp[ni][nj] = dp[i][j] + 1;
					ans = max(ans, dp[ni][nj]);
					q.push({ ni, nj });
				}
			}
		}

		return ans;
	}
};

int main()
{
	//[[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
	Solution s;

	vector<vector<int>> grid = {
		{2, 4, 3, 5},
		{5, 4, 9, 3},
		{3, 4, 2, 11},
		{10, 9, 13, 15}
	};

	cout << s.maxMoves(grid) << endl;

	return 0;
}