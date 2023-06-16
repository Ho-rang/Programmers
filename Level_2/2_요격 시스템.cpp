#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool compare(std::vector<int> a, std::vector<int> b)
{
	return a[0] > b[0];
}

int solution(std::vector<std::vector<int>> targets)
{
	int answer = 0;

	std::sort(targets.begin(), targets.end(), compare);

	int missile = 0;

	for (auto target : targets)
	{

		std::cout << target[0] << " : " << target[1] << " = " << missile << std::endl;
		if (target[0] <= missile && missile < target[1])
			continue;

		else
			missile = target[0];
			answer++;
	}

	return answer;
}

void main()
{
	std::cout << solution(
		{ {4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4} }
	);

}