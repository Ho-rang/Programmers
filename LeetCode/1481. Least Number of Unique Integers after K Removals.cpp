#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

class Solution
{
public:
	int findLeastNumOfUniqueInts(std::vector<int>& arr, int k)
	{
		std::unordered_map<int, int> numCount;

		std::ranges::for_each(arr, [&numCount](auto& n) { numCount[n]++; });
		std::ranges::sort(numCount);

		int result = numCount.size();
		for (auto& count : numCount)
		{
			if (count > k)
				return result;

			k -= count;
			result--;
		}

		return result;
	}
};