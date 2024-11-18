#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> decrypt(vector<int>& code, int k)
	{
		if (k == 0)
			return vector<int>(code.size(), 0);

		vector<int> result(code.size(), 0);

		for (int i = 0; i < code.size(); i++)
		{
			for (int j = 1; j <= abs(k); j++)
			{
				if (k > 0)
					result[i] += code[(i + j) % code.size()];
				else
					result[i] += code[(i - j + code.size()) % code.size()];
			}
		}

		return result;
	}
};