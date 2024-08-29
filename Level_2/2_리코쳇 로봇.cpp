#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int dy[] = { -1,1,0,0 };
constexpr int dx[] = { 0,0,-1,1 };

int solution(vector<string> board)
{
	struct Data
	{
		int y;
		int x;
		int dir;
	};

	queue<Data> bfs;

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] == 'R')
				bfs.push({ i, j , 0 });

	while (!bfs.empty())
	{
		auto [y, x, dir] = bfs.front();
		bfs.pop();

		if (board[y][x] == 'G')
			return dir;

		if (board[y][x] == 'X')
			continue;

		board[y][x] = 'X';

		for (int i = 0; i < 4; i++)
		{
			int ny = y;
			int nx = x;

			while (true)
			{
				ny += dy[i];
				nx += dx[i];

				if (ny < 0 || nx < 0 ||
					ny >= board.size() || nx >= board[ny].size() ||
					board[ny][nx] == 'D')
				{
					ny -= dy[i];
					nx -= dx[i];

					bfs.push({ ny, nx, dir + 1 });

					break;
				}
			}
		}
	}

	return -1;
}