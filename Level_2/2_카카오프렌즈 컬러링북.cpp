#include <vector>
#include <algorithm>

constexpr int dx[] = { -1,1,0,0 };
constexpr int dy[] = { 0,0,-1,1 };

int DFS(int x, int y, std::vector<std::vector<int>>& picture, std::vector<std::vector<bool>>& visited)
{
	if (picture[x][y] == 0 || visited[x][y])
		return 0;

	visited[x][y] = true;

	int count = 1;
	for (int i = 0; i < 4; i++)
	{
		const int nx = x + dx[i];
		const int ny = y + dy[i];

		if (0 <= nx && nx < picture.size() &&
			0 <= ny && ny < picture[0].size())
			count += DFS(nx, ny, picture, visited);
	}

	return count;
}

std::vector<int> solution(int m, int n, std::vector<std::vector<int>> picture)
{
	int numberArea = 0;
	int maxSizeArea = 0;

	std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int area = DFS(i, j, picture, visited);

			if (area > 0)
			{
				maxSizeArea = std::max(maxSizeArea, area);
				numberArea++;
			}
		}
	}

	return { numberArea, maxSizeArea };
}

void main()
{
	solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}} );
}