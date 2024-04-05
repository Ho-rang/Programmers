#include "pch.h"

class Solution
{
public:
	int maxDepth(string s)
	{
		int result = 0;
		int counter = 0;

		for (char c : s)
		{
			if (c == '(')
			{
				counter++;
				result = std::max(result, counter);
			}
			else if (c == ')')
			{
				counter--;
			}
		}

		return result;
	}
};