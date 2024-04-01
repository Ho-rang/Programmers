#include "pch.h"

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int i = s.length() - 1;
		int len = i;
		for (; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				len = i;
				break;
			}
		}

		for (; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				return len - i;
			}
		}

		return len + 1;
	}
};