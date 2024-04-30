#include "pch.h"

class Solution 
{
public:
	long long wonderfulSubstrings(string word) 
	{
		vector<long long> count(1024);
		count[0] = 1;

		int curState = 0;
		long long result = 0;

		for (char c : word)
		{
			curState ^= 1 << (c - 'a');

			result += count[curState];

			for (char odd = 'a'; odd <= 'j'; odd++) 
			{
				int oddState = curState ^ (1 << (odd - 'a'));
				result += count[oddState];
			}

			count[curState]++;
		}

		return result;
	}
};