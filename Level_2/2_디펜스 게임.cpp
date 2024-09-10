#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
	int answer = 0;

	priority_queue<int, std::vector<int>, greater<>> minHeap;
	int sum = 0;

	for (int i = 0; i < enemy.size(); i++)
	{
		if (minHeap.size() < k)
		{
			minHeap.push(enemy[i]);
			continue;
		}

		if (minHeap.top() < enemy[i])
		{
			sum += minHeap.top();
			minHeap.pop();
			minHeap.push(enemy[i]);
		}
		else
		{
			sum += enemy[i];
		}

		if (sum > n)
			return i;
	}


	return enemy.size();
}