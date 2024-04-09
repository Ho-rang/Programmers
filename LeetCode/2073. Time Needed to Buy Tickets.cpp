#include "pch.h"

class Solution
{
public:
	int timeRequiredToBuy(vector<int>& tickets, int k)
	{
		int result = tickets[k];

		for (int i{ 0 }; i < k; i++)
		{
			result += tickets[i] > tickets[k] ? tickets[k] : tickets[i];
		}

		for (int i = k + 1; i < tickets.size(); i++)
		{
			result += tickets[i] < tickets[k] ? tickets[i] : tickets[k] - 1;
		}

		return result;
	}
};