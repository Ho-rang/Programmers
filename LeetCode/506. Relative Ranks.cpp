#include "pch.h"

class Solution
{
public:
	vector<string> findRelativeRanks(vector<int>& score)
	{
		vector<int> temp = score;

		std::sort(temp.begin(), temp.end(), std::greater<int>());

		unordered_map<int, string> rank;

		for (int i = 0; i < temp.size(); i++)
		{
			if (i == 0)
				rank[temp[i]] = "Gold Medal";
			else if (i == 1)
				rank[temp[i]] = "Silver Medal";
			else if (i == 2)
				rank[temp[i]] = "Bronze Medal";
			else
				rank[temp[i]] = to_string(i + 1);
		}
		vector<string> res;

		for (int i = 0; i < score.size(); i++)
			res.push_back(rank[score[i]]);

		return res;
	}
};