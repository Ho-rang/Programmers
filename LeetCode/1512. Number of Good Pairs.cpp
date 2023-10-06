
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution 
{
public:
	int numIdenticalPairs(vector<int>& nums) 
	{
		int answer = 0;

		std::map<int, int> m;

		for (auto num : nums)
		{
			m[num]++;
		}

		for (auto num : m)
		{
			int& count = num.second;

			if(count < 2)
				continue;
			
			answer += (count * (count - 1)) / 2;
		}

		return answer;
	}
};

int main()
{

	return 0;
}