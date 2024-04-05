#include "pch.h"

class Solution
{
public:
	vector<int> findDuplicates(vector<int>& nums)
	{
		vector<int> result;
		unordered_map<int, int> map;

		for (auto num : nums)
		{
			if (map[num]++ == 1)
				result.push_back(num);
		}

		return result;
	}
};