#include <iostream>
#include <algorithm>
#include <vector>

int main()
{	
	int T;
	
	std::cin >> T;

	std::vector<int> dp(11);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (T--)
	{
		int n;
		std::cin >> n;

		for (int i = 4; i < 11; i++)
		{
			if (dp[i] != 0)
				continue;

			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		std::cout << dp[n] << std::endl;
	}

	return 0;
}
