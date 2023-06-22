/*
DFS�� �湮�� ��� ���� * ���ݱ��� �湮�� ��� ����

�� ��� ���ϸ� ������� ���� ���� ������ ���´�
*/
#include <vector>

class Solution
{
private:
	void DFS(std::vector<std::vector<int>>& nodes, int node, std::vector<bool>& check, int& count);
public:
	long long countPairs(int n, std::vector<std::vector<int>>& edges);
};

void Solution::DFS(std::vector<std::vector<int>>& nodes, int nodeIndex, std::vector<bool>& check, int& count)
{
	if (check[nodeIndex])
		return;

	check[nodeIndex] = true;
	count++;

	for (auto node : nodes[nodeIndex])
		DFS(nodes, node, check, count);
}

long long Solution::countPairs(int n, std::vector<std::vector<int>>& edges)
{
	long long answer = 0;

	std::vector<std::vector<int>> graph(n, std::vector<int>());

	for (auto node : edges)
	{
		graph[node[0]].push_back(node[1]);
		graph[node[1]].push_back(node[0]);
	}

	long long visited = 0;

	std::vector<bool> check(n, false);
	for (int i = 0; i < graph.size(); i++)
	{
		int count = 0;
		DFS(graph, i, check, count);

		if (count == 0)
			continue;

		answer += (long long)count * visited;
		visited += count;
	}

	return answer;
}