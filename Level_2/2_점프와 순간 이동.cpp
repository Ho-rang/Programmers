#include <iostream>

int solution(int n)
{
	int ans = 1;

	while (n > 1)
	{
		if (n & 1)
		{
			ans++;
			n -= 1;
		}
		else
		{
			n >>= 1;
		}
	}

	return ans;
}