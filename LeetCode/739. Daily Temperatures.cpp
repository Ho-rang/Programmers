#include <vector>
#include <stack>

class Solution
{
public:
	std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
	{
		std::stack<int> s;
		std::vector<int> result(temperatures.size());

		for (int i = temperatures.size() - 1; i >= 0; i--)
		{
			if (s.empty())
			{
				s.push(i);
				result[i] = 0;
				continue;
			}

			while (!s.empty() && temperatures[i] >= temperatures[s.top()])
				s.pop();

			if (s.empty())
				result[i] = 0;
			else
				result[i] = s.top() - i;

			s.push(i);
		}


		return result;
	}
};