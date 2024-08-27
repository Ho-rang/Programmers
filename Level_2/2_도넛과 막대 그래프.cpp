#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
	vector<int> answer(4);

	unordered_map<int, int> in;
	unordered_map<int, int> out;
	unordered_map<int, vector<int>> path;
	for (auto& edge : edges)
	{
		in[edge[1]]++;
		in[edge[0]];
		out[edge[0]]++;
		out[edge[1]];
		path[edge[0]].push_back(edge[1]);
	}

	for (auto& [key, value] : in)
	{
		if (value == 0 && out[key] >= 2)
		{
			answer[0] = key;
			break;
		}
	}

	vector<int> start = path[answer[0]];
	for (auto startVertex : start)
	{
		queue<int> q;
		q.push(startVertex);

		// �ٷ� ���������� üũ�ϱ� ���� ����
		bool isStart = false;
		bool isCount = false;

		while (!q.empty())
		{
			int nowNode = q.front();
			q.pop();

			// ������������ ���ƿ��� ����
			if (isStart && nowNode == startVertex)
			{
				answer[1]++;
				isCount = true;
				break;
			}
			isStart = true;

			// ������ 2���� 8��
			if (path[nowNode].size() >= 2)
			{
				answer[3]++;
				isCount = true;
				break;
			}

			for (auto nextNode : path[nowNode])
			{
				q.push(nextNode);
			}
		}

		// ���� ����Ǿ� ���� ������ ������
		if (!isCount)
			answer[2]++;
	}

	return answer;
}

int main()
{
	// [[2, 3], [4, 3], [1, 1], [2, 1]]
	vector<vector<int>> edges = { {2, 3}, {4, 3}, {1, 1}, {2, 1} };
	vector<int> result = solution(edges); // [1, 1, 0, 1]

	return 0;
}