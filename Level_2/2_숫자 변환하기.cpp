#include <string>
#include <vector>
#include <queue>
#include <utility>

int BFS(int x, const int y, const int n)
{
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(0, x));

	std::vector<bool> check((y + 1) * 3);

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		if (now.second == y)
			return now.first;

		else if (now.second > y)
			continue;

		now.first++;
		{
			auto next = now;
			next.second += n;

			if(!check[next.second])
			{
				check[next.second] = true;
				q.push(next);
			}
		}
		{
			auto next = now;
			next.second *= 2;
			if (!check[next.second])
			{
				check[next.second] = true;
				q.push(next);
			}
		}
		{
			auto next = now;
			next.second *= 3;
			if (!check[next.second])
			{
				check[next.second] = true;
				q.push(next);
			}
		}
	}

	return -1;
}

int solution(int x, int y, int n)
{
	int answer = 0;

	answer = BFS(x, y, n);

	return answer;
}

void main()
{
	solution(2, 5, 4);
}