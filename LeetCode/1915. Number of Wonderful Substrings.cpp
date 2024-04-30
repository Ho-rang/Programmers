#include "pch.h"

class Solution {
public:
	long long wonderfulSubstrings(string word) 
	{
		vector<long long> cnt(1024);
		cnt[0] = 1;

		int curState = 0;
		long long result = 0;

		for (char c : word)
		{
			curState ^= 1 << (c - 'a');

			result += cnt[curState];

			for (char odd = 'a'; odd <= 'j'; odd++) 
			{
				int oddState = curState ^ (1 << (odd - 'a'));
				result += cnt[oddState];
			}

			cnt[curState]++;
		}

		return result;
	}
};