#include <string>
#include <vector>
#include <algorithm>
#include <set>


int solution(std::vector<int> topping)
{
	int answer = 0;

	std::vector<int> toppingData1(10001);
	std::vector<int> toppingData2(10001);

	int kind1 = 0;
	int kind2 = 0;
	for (const auto topp : topping)
	{
		if (toppingData2[topp] == 0)
			kind2 += 1;

		toppingData2[topp] += 1;
	}

	for (const auto topp : topping)
	{
		if (toppingData1[topp] == 0)
			kind1 += 1;

		toppingData1[topp] += 1;

		toppingData2[topp] -= 1;
		if (toppingData2[topp] == 0)
			kind2 -= 1;

		if (kind1 == kind2)
		{
			++answer;
		}
		if (kind1 > kind2)
		{
			break;
		}
	}
	return answer;
}