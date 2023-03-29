#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int solution(std::vector<int> picks, std::vector<std::string> minerals)
{
	int answer = 0;

	const std::vector<std::vector<int>> cost = { {1,1,1},{5,1,1},{25,5,1} };

	std::vector<std::vector<int>> mineral;

	int size = picks[0] + picks[1] + picks[2];
	for (auto i = 0; i < minerals.size() && i < size * 5; i += 5)
	{
		std::vector<int> temp(3);
		for (auto j = 0; j < 5 && i + j < minerals.size(); j++)
		{
			if (minerals[j + i].compare("diamond") == 0)
				temp[0]++;
			else if (minerals[j + i].compare("iron") == 0)
				temp[1]++;
			else if (minerals[j + i].compare("stone") == 0)
				temp[2]++;
		}
		mineral.emplace_back(temp);
	}
	
	std::sort(mineral.begin(), mineral.end(),
		[](auto& a, auto& b)
		{
			if (a[0] > b[0])
				return true;
			
			if (a[0] == b[0] && a[1] > b[1])
				return true;
			
			if (a[0] == b[0] && a[1] == b[1] && a[2] > b[2])
				return true;
			
			return false;
		});

	int index = 0;
	for (auto m : mineral)
	{
		while (index < 3 && picks[index] == 0 )
		{
			index++;
		}

		if (index >= 3)
			break;

		picks[index] -= 1;

		answer += cost[index][0] * m[0];
		answer += cost[index][1] * m[1];
		answer += cost[index][2] * m[2];
	}

	return answer;
}