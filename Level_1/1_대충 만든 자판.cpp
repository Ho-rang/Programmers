#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
	vector<int> answer;

	std::unordered_map<char, int> map;
	for (int i = 0; i < keymap.size(); i++)
	{
		for (int j = 0; j < keymap[i].length(); j++)
		{
			auto key = keymap[i][j];
			if (map[key] == 0)
			{
				map[key] = j + 1;
			}
			else if(map[key] > j + 1)
			{
				map[key] = j + 1;
			}
		}
	}

	for (auto target : targets)
	{
		int sum = 0;
		for (auto a : target)
		{
			if (map[a] == 0)
			{
				sum = -1;
				break;
			}
			sum += map[a];
		}
		answer.push_back(sum);
	}


	return answer;
}