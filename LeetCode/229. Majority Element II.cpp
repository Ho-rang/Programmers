
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <sstream>



#include <algorithm>
#include <map>

class Solution
{
public:
	vector<int> majorityElement(vector<int>& nums)
	{
		std::vector<int> answer;

		std::map<int, int> m;

		for (auto num : nums)
		{
			m[num]++;
		}

		for (auto count : m)
		{
			if (nums.size() / 3 < count.second)
				answer.push_back(count.first);
		}

		std::sort(answer.begin(), answer.end());

		return answer;
	}
};

int main()
{

	return 0;
}