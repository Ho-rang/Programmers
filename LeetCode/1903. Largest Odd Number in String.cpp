#include <string>

class Solution
{
public:
	std::string largestOddNumber(std::string num)
	{
		if (num.back() & 1)
			return num;

		int i = num.length() - 1;
		while (i >= 0)
		{
			if (num[i] & 1)
				return num.substr(0, i + 1);
			else
				i--;
		}

		return "";
	}
};