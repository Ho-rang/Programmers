#include <string>

class Solution
{
public:
	int countHomogenous(std::string s)
	{
		long long result = 0;

		long long count = 1;
		char prev = s[0];

		for (int i = 1; i < s.length(); i++)
		{
			if (prev != s[i])
			{
				result += (count * (count + 1)) / 2;
				prev = s[i];
				count = 1;
			}
			else
			{
				count++;
			}
		}
		result += (count * (count + 1)) / 2;

		return result % 1000000007;
	}
};