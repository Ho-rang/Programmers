#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
	bool uniqueOccurrences(std::vector<int>& arr)
	{
		std::unordered_map<int, int> hashMap;

		for (int i = 0; i < arr.size(); i++)
			hashMap[arr[i]]++;

		std::unordered_map<int, int> countMap;

		for (const auto& num : hashMap)
			countMap[num.second]++;

		for (const auto& count : countMap)
			if (count.second > 1)
				return false;

		return true;
	}
};