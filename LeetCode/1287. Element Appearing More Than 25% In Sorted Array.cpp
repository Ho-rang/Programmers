#include <vector>

class Solution
{
public:
	int findSpecialInteger(std::vector<int>& arr)
	{
		int quarter = arr.size() / 4;

		for (int i = 0; i < arr.size() - quarter; i++)
		{
			if (arr[i] == arr[i + quarter])
				return arr[i];
		}

		return 0;
	}
};