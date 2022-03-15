#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<int>> graph(n + 1);

	//양방향 그래프 만들기
	for (int i = 0; i < edge.size(); i++)
	{
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}

	vector<int> dist(n + 1, -1); //방문확인겸 거리
	queue<int> q;

	dist[1] = 0; //1부터 시작이니 1은 거리 0
	q.push(1); //1부터 시작

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (auto next : graph[current]) //current에서 갈수있는 번호 순회
		{
			if (dist[next] == -1) //갈수있는 번호 안갔을때 작동
			{
				dist[next] = dist[current] + 1; //노드 하나 이동했으니 이동거리 + 1
				q.push(next); //이동하고 해당자리에서 다시 탐색
			}
		}
	}

	int max = *max_element(dist.begin(), dist.end());

	for (auto a : dist)
		if (a == max)
			answer++;

	return answer;
}