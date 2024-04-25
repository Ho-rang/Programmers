#include "pch.h"

class Solution
{
public:
	int longestIdealString(string s, int k)
	{
		vector<int> dp(26);

		for (int i = 0; i < s.size(); i++)
		{
			int alpha = s[i] - 'a';
			dp[alpha]++;
			for (int j = std::max(alpha - k, 0); j <= std::min(alpha + k, 25); j++)
				dp[j] = std::max(dp[j], dp[alpha]);
		}

		return *std::max_element(dp.begin(), dp.end());
	}
};