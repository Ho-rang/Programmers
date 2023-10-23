#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int n)
	{
		if (n == 1)
			return true;

		if (n <= 0)
			return false;

		if ((n & 0x5555) % 4 == 0)
			return true;

		return false;
	}
};