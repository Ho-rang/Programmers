#include <string>
#include <vector>
#include <algorithm>

int solution(int k, std::vector<std::vector<int>> dungeons)
{
	int answer = 0;

	sort(dungeons.begin(), dungeons.end());

	do 
	{
		int fatigue = k;
		int count = 0;

		for (auto dungeon : dungeons)
		{
			if (fatigue < dungeon[0])
				break;

			fatigue -= dungeon[1];

			count++;
		}

		if (answer < count)
			answer = count;

	} while (next_permutation(dungeons.begin(),dungeons.end()));

	return answer;
}