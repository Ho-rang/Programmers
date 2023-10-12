#include <string>
#include <vector>

using namespace std;

void DFS(int n, std::vector<bool>& visited, vector<vector<int>>& computers)
{
	visited[n] = true;

	for (int i = 0; i < computers[n].size(); i++)
	{
		if (computers[n][i] == 1 && visited[i] == false)
		{
			DFS(i, visited, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	std::vector<bool> visited(n);

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == true)
			continue;

		DFS(i, visited, computers);
		answer++;
	}

	return answer;
}