#include <vector>
#include <queue>

int BFS(std::vector<std::vector<int>>& maps)
{
	constexpr int dx[] = { -1,1,0,0 };
	constexpr int dy[] = { 0,0,-1,1 };

	struct Data
	{
		int x;
		int y;
		int distance;
	};

	std::queue<Data> q;

	q.push({ 0,0,0 });

	while (!q.empty())
	{
		auto matrix = q.front();
		q.pop();

		if (maps[matrix.x][matrix.y] == 0)
			continue;
		else
			maps[matrix.x][matrix.y] = 0;
		
		matrix.distance++;

		if (matrix.x == maps.size() - 1 &&
			matrix.y == maps[0].size() - 1)
			return matrix.distance;


		for (int i = 0; i < 4; i++)
		{
			int nx = matrix.x + dx[i];
			int ny = matrix.y + dy[i];

			if (nx < 0 || nx >= maps.size() ||
				ny < 0 || ny >= maps[0].size())
				continue;

			q.push({ nx, ny , matrix.distance});
		}
	}

	return -1;
}

int solution(std::vector<std::vector<int>> maps)
{
	return BFS(maps);
}

#include <iostream>
void main()
{
}