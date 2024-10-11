#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
	int smallestChair(vector<vector<int>>& times, int targetFriend)
	{
		int targetArrival = times[targetFriend][0];

		sort(times.begin(), times.end());

		priority_queue<int, vector<int>, greater<int>> availableChairs;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyChairs;

		for (int i = 0; i < times.size(); ++i)
			availableChairs.push(i);

		for (int i = 0; i < times.size(); ++i)
		{
			int arrival = times[i][0];
			int leave = times[i][1];

			while (!busyChairs.empty() && busyChairs.top().first <= arrival)
			{
				availableChairs.push(busyChairs.top().second);
				busyChairs.pop();
			}

			int chair = availableChairs.top();
			availableChairs.pop();

			if (arrival == targetArrival)
				return chair;

			busyChairs.push({ leave, chair });
		}

		return -1;
	}
};