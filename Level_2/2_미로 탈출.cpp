#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int BFS(
	const pair<int, int>& start,
	const pair<int, int>& target,
	const vector<string>& maps)
{
	const int dx[] = { -1,1,0,0 };
	const int dy[] = { 0,0,-1,1 };

	const int maxX = maps.size();
	const int maxY = maps[0].length();

	bool visited[100][100] = { false, };

	queue<pair<pair<int, int>, int>> q;

	q.push({ start, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		const int x = q.front().first.first;
		const int y = q.front().first.second;
		const int sec = q.front().second;
		q.pop();

		if (x == target.first &&
			y == target.second)
			return sec;

		for (int i = 0; i < 4; i++)
		{
			const int nx = x + dx[i];
			const int ny = y + dy[i];

			if (nx < 0 || nx >= maxX ||
				ny < 0 || ny >= maxY)
				continue;

			if ((maps[nx][ny] == 'X') || visited[nx][ny])
				continue;

			q.push({ {nx, ny}, sec + 1 });
			visited[nx][ny] = true;
		}
	}

	return 0;
}

int solution(vector<string> maps)
{
	int answer = 0;

	pair<int, int> start(-1, -1);
	pair<int, int> exit(-1, -1);
	pair<int, int> lever(-1, -1);

	int findCount = 0;
	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[0].size(); j++)
		{
			if (findCount == 3)
				break;

			if (maps[i][j] == 'S')
			{
				start = { i,j };
				findCount++;
			}
			if (maps[i][j] == 'E')
			{
				exit = { i,j };
				findCount++;
			}
			if (maps[i][j] == 'L')
			{
				lever = { i,j };	
				findCount++;
			}
		}
	}
	///
	{
		const int first = BFS(start, lever, maps);
		if (first == 0)
			return -1;

		answer += first;
	}

	{
		const int second = BFS(lever, exit, maps);
		if (second == 0)
			return -1;
		answer += second;
	}

	return answer;
}