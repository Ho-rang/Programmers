#include <string>
#include <algorithm>

std::string solution(int n)
{
	std::string answer = "";

	char number[] = { '4','1','2' };

	while (n != 0)
	{
		answer += number[n % 3];
		n = (n - 1) / 3;
	}

	std::reverse(answer.begin(), answer.end());

	std::string result = { answer.rbegin(), answer.rend() };

	return result;
}