class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		while (n > 0)
		{
			if (n & 1)
				if (n == 1)
					return true;
				else
					return false;
			else
				n >>= 1;
		}
		return false;
	}
};