#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int longestSquareStreak(vector<int>& nums)
	{
		int result = -1;

		sort(nums.begin(), nums.end());
		unordered_map<int, bool> map;
		for (int i : nums)
			map[i] = true;


		for (int num : nums)
		{
			if (map[num] == false)
				continue;

			int len = 0;

			queue<int> q;
			q.push(num);

			while (!q.empty())
			{
				int front = q.front();
				q.pop();

				len++;
				map[front] = false;

				if (map[(long long)front * front])
					q.push((long long)front * front);
			}

			if (len >= 2)
				result = max(result, len);
		}

		return result;
	}
};