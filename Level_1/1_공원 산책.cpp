#include <string>
#include <vector>

std::vector<int> solution(std::vector<std::string> park, std::vector<std::string> routes)
{
	std::vector<int> answer = { -1,-1 };

	for (int i = 0; i < park.size(); i++)
	{
		for (int j = 0; j < park[0].size(); j++)
		{
			if (park[i][j] == 'S')
			{
				answer[0] = i;
				answer[1] = j;
				break;
			}
		}
		if (answer[0] == i)
			break;
	}

	for (auto str : routes)
	{
		const int dist = str[2] - '0';

		int dx = 0;
		int dy = 0;

		if (str[0] == 'E')
			dy = 1;
		else if (str[0] == 'W')
			dy = -1;
		else if (str[0] == 'N')
			dx = -1;
		else if (str[0] == 'S')
			dx = 1;

		const int nx = dx * dist + answer[0];
		const int ny = dy * dist + answer[1];

		if (nx < 0 || nx >= park.size() ||
			ny < 0 || ny >= park[0].size() ||
			park[nx][ny] == 'X')
			continue;

		bool flag = false;
		for (int i = answer[0]; i != nx; i > nx ? i-- : i++)
			if (park[i][answer[1]] == 'X')
			{
				flag = true;
				break;
			}

		for (int j = answer[1]; j != ny; j > ny ? j-- : j++)
			if (park[answer[0]][j] == 'X')
			{
				flag = true;
				break;
			}
		
		if(flag)
			continue;
		
		answer[0] = nx;
		answer[1] = ny;
	}

	return answer;
}

void main()
{
	solution({ "SOO", "OXX", "OOO" }, { "E 2","S 2","W 1" });
}