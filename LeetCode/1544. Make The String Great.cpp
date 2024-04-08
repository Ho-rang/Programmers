#include <string>
#include <vector>

class Solution
{
public:
	std::string makeGood(std::string s)
	{
		std::vector<char> v;

		for (char c : s)
		{
			if (!v.empty() && abs(v.back() - c) == 32)
				v.pop_back();
			else
				v.push_back(c);
		}

		return std::string(v.begin(), v.end());
	}
};