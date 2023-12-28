#include <string>
#include <vector>
#include <set>
#include <algorithm>

constexpr int dx[] = { -1,1,0,0 };
constexpr int dy[] = { 0,0,-1,1 };

void Drilling(int y, int x, int& count, std::set<int>& oilIndex, std::vector<std::vector<int>>& land)
{
	count++;

	land[y][x] = 0;
	oilIndex.insert(x);

	for (int i = 0; i < 4; i++)
	{
		const int ny = dy[i] + y;
		const int nx = dx[i] + x;

		if (ny < 0 || ny >= land.size() ||
			nx < 0 || nx >= land[0].size())
			continue;

		if (land[ny][nx] == 1)
			Drilling(ny, nx, count, oilIndex, land);
	}
}

int solution(std::vector<std::vector<int>> land)
{
	int answer = 0;

	std::vector<int> oil(land[0].size());

	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land[0].size(); j++)
		{
			if (land[i][j] == 0)
				continue;

			std::set<int> oilIndex;
			int count = 0;
			Drilling(i, j, count, oilIndex, land);

			for (const auto idx : oilIndex)
				oil[idx] += count;

		}
	}

	return *std::max_element(oil.begin(), oil.end());
}