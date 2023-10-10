#include <vector>

#include <math.h>

class Solution
{
public:
	int integerBreak(int n)
	{
		if (n == 2)
			return 1;
		else if (n == 3)
			return 2;

		int threeCount = n / 3;
		n %= 3;

		if (n == 1 && threeCount > 0)
		{
			threeCount--;
			n = 4;
		}

		int twoCount = n / 2;
		n %= 2;

		int result = pow(3, threeCount);

		return result << twoCount;
	}
};

void main()
{
	Solution s;
	s.integerBreak(4);
}