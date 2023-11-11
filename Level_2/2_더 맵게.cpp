#include <string>
#include <vector>
#include <queue>

int solution(std::vector<int> scoville, int K)
{
	int answer = 0;

	std::priority_queue<int, std::vector<int>, std::less<int>> scovilleHeap(scoville.begin(), scoville.end());

	while (true)
	{
		int first = scovilleHeap.top();

		if (first >= K)
			break;

		scovilleHeap.pop();
		int second = scovilleHeap.top();
		scovilleHeap.pop();

		scovilleHeap.push(first + second * 2);

		answer++;
	}

	return answer;
}