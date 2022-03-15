#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<int>> graph(n + 1);

	//����� �׷��� �����
	for (int i = 0; i < edge.size(); i++)
	{
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}

	vector<int> dist(n + 1, -1); //�湮Ȯ�ΰ� �Ÿ�
	queue<int> q;

	dist[1] = 0; //1���� �����̴� 1�� �Ÿ� 0
	q.push(1); //1���� ����

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (auto next : graph[current]) //current���� �����ִ� ��ȣ ��ȸ
		{
			if (dist[next] == -1) //�����ִ� ��ȣ �Ȱ����� �۵�
			{
				dist[next] = dist[current] + 1; //��� �ϳ� �̵������� �̵��Ÿ� + 1
				q.push(next); //�̵��ϰ� �ش��ڸ����� �ٽ� Ž��
			}
		}
	}

	int max = *max_element(dist.begin(), dist.end());

	for (auto a : dist)
		if (a == max)
			answer++;

	return answer;
}