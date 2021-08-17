#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int count = 0;
	int zero_count = 0;

	for (auto lotto : lottos)
	{
		if (lotto == 0)
		{
			zero_count++;
			continue;
		}

		for (auto win : win_nums)
			if (lotto == win)
				count++;
	}

	answer.push_back(7 - max(count + zero_count, 1));
	answer.push_back(7 - max(count, 1));

	return answer;
}
