#include <string>
#include <vector>

class Solution
{
public:
	int maxScore(std::string s)
	{
		int one = std::count(s.begin(), s.end(), '1');

		int result = 0;

		int zero = 0;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s[i] == '0')
				one--;
			else
				zero++;

			result = std::max(result, one + zero);
		}

		return result;
	}
};