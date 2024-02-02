#include <vector>
#include <string>

class Solution
{
public:
	std::vector<int> sequentialDigits(int low, int high)
	{
		std::vector<int> result;
		std::string number = "123456789";

		int lowCount = 0;
		{
			int tempNum = low;
			while (tempNum != 0)
			{
				tempNum /= 10;
				++lowCount;
			}
		}
		int highCount = 0;
		{
			int tempNum = high;
			while (tempNum != 0)
			{
				tempNum /= 10;
				++highCount;
			}
		}

		for (int len = lowCount; len <= highCount; len++)
		{
			for (int i = 0; i <= 9 - len; i++)
			{
				int num = std::stoi(number.substr(i, len));
				if (low > num)
					continue;
				else if (num > high)
					return result;
				else
					result.push_back(num);
			}
		}

		return result;
	}
};