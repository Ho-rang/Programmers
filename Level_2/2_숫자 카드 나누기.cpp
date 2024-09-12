#include <string>
#include <vector>
#include <algorithm>

std::vector<int> findDivisors(int n)
{
	std::vector<int> divisors;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			divisors.push_back(i);
			if (i != n / i)
				divisors.push_back(n / i);
		}
	}
	std::sort(divisors.begin() + 1, divisors.end(), std::greater<>());
	return std::vector<int>(divisors.begin() + 1, divisors.end());
}

bool isDivisor(const std::vector<int>& array, int n)
{
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % n != 0)
			return false;
	}
	return true;
}

bool isUnDivisor(const std::vector<int>& array, int n)
{
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % n == 0)
			return false;
	}
	return true;
}

int calculate(const std::vector<int>& arrayA, const std::vector<int>& arrayB, std::vector<int> divisors)
{
	int result = 0;

	for (int i = 1; i < divisors.size(); i++)
	{
		bool check = false;

		for (int div : divisors)
		{
			if (isDivisor(arrayA, div) && isUnDivisor(arrayB, div))
			{
				check = true;
				result = div;
				break;
			}
		}

		if (check)
			break;;
	}

	return result;
}

int solution(std::vector<int> arrayA, std::vector<int> arrayB)
{
	int answer = 0;

	answer = std::max(
		calculate(arrayA, arrayB, findDivisors(arrayA[0])),
		calculate(arrayB, arrayA, findDivisors(arrayB[0]))
	);

	return answer;
}