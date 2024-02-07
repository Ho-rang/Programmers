#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
	{
		std::unordered_map<std::string, std::vector<std::string>> hashMap;
		std::vector<std::vector<std::string>> result;

		for (const auto& s : strs)
		{
			std::string str = s;
			std::sort(str.begin(), str.end());
			hashMap[str].push_back(s);
		}


		for (auto& [_, str] : hashMap)
			result.push_back(std::move(str));

		return result;
	}
};