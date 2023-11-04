#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> buildArray(std::vector<int>& target, int n)
	{
		std::vector<std::string> result;
		int currentNum = 1;
		for (int i = 0; i < target.size(); i++)
		{
			for (int j = 0; j < target[i] - currentNum; j++)
			{
				result.push_back("Push");
				result.push_back("Pop");
			}

			result.push_back("Push");

			currentNum = target[i];
		}
	}
};