#include <vector>
#include <string>
#include <stack>

class Solution
{
public:
	int evalRPN(std::vector<std::string>& tokens)
	{
		std::stack<int> result;
		const int size = tokens.size();
		for (int i = 0; i < size; i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int a = result.top();
				result.pop();
				int b = result.top();
				result.pop();
				int num;
				if (tokens[i] == "+")
					num = (b + a);
				else if (tokens[i] == "-")
					num = (b - a);
				else if (tokens[i] == "*")
					num = (b * a);
				else if (tokens[i] == "/")
					num = (b / a);
				result.push(num);
			}
			else
			{
				result.push(std::stoi(tokens[i]));
			}
		}
		return result.top();
	}
};