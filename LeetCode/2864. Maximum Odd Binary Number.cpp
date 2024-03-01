#include <string>
#include <algorithm>
#include <ranges>

class Solution
{
public:
	std::string maximumOddBinaryNumber(std::string s)
	{
		if (s.length() == 1)
			return s;

		std::ranges::sort(s, std::greater<char>());

		return s.substr(1, s.length() - 1) + s[0];
	}
};