#include <vector>
#include <algorithm>

class Solution
{
public:
	int buyChoco(std::vector<int>& prices, int money)
	{
		int a = 101;
		int b = 101;

		for (const auto& price : prices)
		{
			if (a > price)
			{
				b = a;
				a = price;
			}
			else if (b > price)
			{
				b = price;
			}
		}

		
		return money - (a + b) >= 0 ? money - (a + b) : money;
	}
};