#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100][100] = { 0, };
const int dx[] = { -1,	1,	0,	0 };
const int dy[] = { 0,	0,	-1,	1 };
int DFS(int x, int y, const vector<string>& maps)
{
	if (visited[x][y] || maps[x][y] == 'X')
		return 0;

	visited[x][y] = true;

	int sum = (maps[x][y] - '0');

	for (int i = 0; i < 4; i++)
	{
		const int nx = x + dx[i];
		const int ny = y + dy[i];
		if (nx < 0 || nx >= maps.size() ||
			ny < 0 || ny >= maps[0].length())
			continue;

		sum += DFS(nx, ny, maps);
	}

	return sum;
}

vector<int> solution(vector<string> maps)
{
	vector<int> answer;

	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[0].length(); j++)
		{
			int sum = DFS(i, j, maps);

			if (sum > 0)
				answer.push_back(sum);
		}
	}

	sort(answer.begin(), answer.end());
	
	return answer;
}