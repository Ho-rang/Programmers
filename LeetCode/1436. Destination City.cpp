#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
	std::string destCity(std::vector<std::vector<std::string>>& paths)
	{
		std::vector<std::string> start(paths.size());
		std::vector<std::string> end(paths.size());

		for (int i = 0 ; i < paths.size() ;i++)
		{
			start.push_back(paths[i][0]);
			end.push_back(paths[i][1]);
		}

		std::sort(start.begin(), start.end());
		std::sort(end.begin(), end.end());

		for (int i = 0, j = 0; i < start.size() - 1; i++, j++)
		{
			if (start[i] != end[j])
			{
				if (start[i + 1] != end[j])
				{
					return end[j];
				}
				else
				{
					i++;
				}
			}
		}

		return end.back();
	}
};