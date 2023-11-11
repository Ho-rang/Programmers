#include <string>
#include <vector>
#include <queue>

int solution(std::vector<int> scoville, int K)
{
	int answer = 0;

	std::priority_queue<int, std::vector<int>, std::greater<int>> scovilleHeap(scoville.begin(), scoville.end());

	while (true)
	{
		int first = scovilleHeap.top();
		scovilleHeap.pop();

		if (first >= K)
			return answer;

		else if (scovilleHeap.empty())
			return -1;

		answer++;

		int second = scovilleHeap.top();
		scovilleHeap.pop();

		scovilleHeap.push(first + second * 2);
	}

	return answer;
}