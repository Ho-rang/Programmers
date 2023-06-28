#include <string>
#include <vector>
#include <algorithm>

bool Compare(const std::vector<int>& a, const std::vector<int>& b)
{
	return a[0] + a[1] > b[0] + b[1];
}

int solution(std::vector<std::vector<int>> scores)
{
	int answer = 1;

	const std::vector<int>& wanho = scores[0];

	std::sort(scores.begin() + 1, scores.end(), Compare);

	for (int i = scores.size() - 1 ; i >= 0; i--)
	{
		if (wanho[0] < scores[i][0] &&
			wanho[1] < scores[i][1])
			return -1;

		if (wanho[0] + wanho[1] < scores[i][0] + scores[i][1])
		{
			bool check = false;
			for (int j = 0 ; j < scores.size() ; j++)
			{
				if (scores[i][0] < scores[j][0] &&
					scores[i][1] < scores[j][0])
				{
					check = true;
					break;
				}
			}

			if(!check)
				answer++;
		}
	}

	return answer;
}