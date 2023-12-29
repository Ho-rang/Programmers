#include <string>
#include <vector>

int solution(std::string dirs)
{
	enum
	{
		NONE = 0b0000,
		UP = 0b1000,
		DOWN = 0b0100,
		LEFT = 0b0010,
		RIGHT = 0b0001,
	};

	int answer = 0;

	char passedRoad[11][11] = { 0 };

	int y = 5;
	int x = 5;
	for (const auto& dir : dirs)
	{
		int ny = y;
		int nx = x;

		char flag = 0;
		char nFlag = 0;
		switch (dir)
		{
			case 'U':
				ny -= 1;
				flag = UP;
				nFlag = DOWN;
				break;
			case 'D':
				ny += 1;
				flag = DOWN;
				nFlag = UP;
				break;
			case 'L':
				nx -= 1;
				flag = LEFT;
				nFlag = RIGHT;
				break;
			case 'R':
				nx += 1;
				flag = RIGHT;
				nFlag = LEFT;
				break;
			default:
				break;
		}

		if (ny < 0 || ny > 10 ||
			nx < 0 || nx > 10)
			continue;

		if ((passedRoad[y][x] & flag) == NONE)
		{
			passedRoad[y][x] |= flag;
			passedRoad[ny][nx] |= nFlag;
			answer++;
		}

		y = ny;
		x = nx;
	}

	return answer;
}