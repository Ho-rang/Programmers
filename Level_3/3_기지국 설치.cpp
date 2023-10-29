#include <vector>

int solution(int n, std::vector<int> stations, int w)
{
	int answer = 0;

	const int width = w * 2 + 1;
	stations.push_back(n + w + 1);

	int index = 1;
	for (const auto& station : stations)
	{
		if (index < station - w)
			answer += (station - w - index - 1) / width + 1;

		index = station + w + 1;
	}

	return answer;
}