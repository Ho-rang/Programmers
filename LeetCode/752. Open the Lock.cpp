#include "pch.h"

class Solution
{
public:
	int openLock(vector<string>& deadends, string target)
	{
		unordered_map<string, bool> dead;

		for (auto& d : deadends)
			dead[d] = true;

		queue<pair<string, int>> q;
		q.push({ "0000",0 });

		while (!q.empty())
		{
			auto [currentNum, count] = q.front();
			q.pop();

			if (dead[currentNum])
				continue;

			if (currentNum == target)
				return count;

			dead[currentNum] = true;

			for (int i = 0; i < 4; i++)
			{
				string up = currentNum;
				string down = currentNum;

				up[i] = up[i] == '9' ? '0' : up[i] + 1;
				down[i] = down[i] == '0' ? '9' : down[i] - 1;

				if (!dead[up])
					q.push({ up, count + 1 });

				if (!dead[down])
					q.push({ down, count + 1 });
			}

		}

		return -1;
	}
};