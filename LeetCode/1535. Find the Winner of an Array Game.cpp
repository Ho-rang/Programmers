#include <vector>
#include <algorithm>

class Solution
{
public:
	int getWinner(std::vector<int>& arr, int k)
	{
		if (k >= arr.size())
			return *std::max_element(arr.begin(), arr.end());

		int maxNum = arr[0];
		int winCount = 0;
		for (int i = 1; i < arr.size(); i++)
		{
			if (maxNum > arr[i])
			{
				winCount++;
			}
			else
			{
				maxNum = arr[i];
				winCount = 1;
			}

			if (winCount == k)
				break;
		}

		return maxNum;
	}
};