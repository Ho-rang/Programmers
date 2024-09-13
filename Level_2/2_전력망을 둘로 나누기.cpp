#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
	int answer = n - 1;

	unordered_map<int, vector<int>> graph;

	for (int i = 0; i < wires.size(); i++)
	{
		graph[wires[i][0]].push_back(wires[i][1]);
		graph[wires[i][1]].push_back(wires[i][0]);
	}

	for (auto [a, b] : graph)
	{
		for (int i = 0; i < b.size(); i++)
		{
			vector<bool> visited(n + 1, false);
			vector<int> stack;
			stack.push_back(a);
			visited[a] = true;
			visited[b[i]] = true;

			int count = 0;
			while (!stack.empty())
			{
				int node = stack.back();
				stack.pop_back();

				count++;

				for (int j = 0; j < graph[node].size(); j++)
				{
					if (visited[graph[node][j]] == false)
					{
						stack.push_back(graph[node][j]);
						visited[graph[node][j]] = true;
					}
				}
			}

			answer = min(answer, abs(count - (n - count)));
		}
	}
	return answer;
}