#include <string>
#include <algorithm>

class Solution
{
public:
	std::string largestGoodInteger(std::string num)
	{
		int result = -1;

		int length = 1;

		for (int i = 1; i < num.length(); i++)
		{
			if (num[i - 1] == num[i])
			{
				if (length == 2)
				{
					result = std::max(result, 111 * (num[i] - '0'));
				}
				else
				{
					length++;
				}
			}
			else
			{
				length = 1;
			}
		}

		if (result > 0)
			return std::to_string(result);
		else if (result == 0)
			return "000";
		else
			return "";
	}
};