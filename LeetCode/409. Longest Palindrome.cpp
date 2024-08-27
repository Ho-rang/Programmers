#include "pch.h"

class Solution
{
public:
	int longestPalindrome(string s)
	{
		int result = 0;
		bool odd = false;
		vector<int> freq('z' - 'A' + 1);

		for (auto c : s)
			freq[c - 'A']++;

		for (auto count : freq)
		{
			if (count & 1)
			{
				odd = true;
				result += count - 1;
			}
			else
			{
				result += count;
			}
		}

		return result + odd;
	}
};