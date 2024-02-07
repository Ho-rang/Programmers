#include <string>
#include <vector>
#include <ranges>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
	std::string frequencySort(std::string s)
	{
		std::string result = "";

		std::unordered_map<char, int> hashMap;
		std::ranges::for_each(s, [&hashMap](auto& c) { hashMap[c]++; });

		std::vector<std::pair<char, int>> v(hashMap.begin(), hashMap.end());

		std::ranges::sort(v, [](auto& a, auto& b) { return a.second > b.second; });

		std::ranges::for_each(v, [&result](auto& pair) { result += std::string(pair.second, pair.first); });

		return result;
	}
};