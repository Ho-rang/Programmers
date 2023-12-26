#include <vector>
#include <queue>

int solution(std::vector<std::vector<int>> maps)
{
	struct Data
	{
		int x;
		int y;
		int distance;
	};

	constexpr int dx[] = { -1,1,0,0 };
	constexpr int dy[] = { 0,0,-1,1 };

	std::queue<Data> bfs;
	bfs.push({ 0, 0, 1 });

	while (!bfs.empty())
	{
		auto data = bfs.front();
		bfs.pop();

		if (maps[data.y][data.x] == 0)
			continue;

		if (data.x == maps[0].size() - 1 &&
			data.y == maps.size() - 1)
			return data.distance;

		maps[data.y][data.x] = 0;
		data.distance++;

		for (int i = 0; i < 4; i++)
		{
			int nx = data.x + dx[i];
			int ny = data.y + dy[i];

			if (nx < 0 || nx >= maps[0].size() ||
				ny < 0 || ny >= maps.size())
				continue;

			bfs.push({ nx,ny,data.distance });
		}
	}

	return -1;
}