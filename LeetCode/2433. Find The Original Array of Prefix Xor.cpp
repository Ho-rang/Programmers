#include <vector>

class Solution
{
public:
	std::vector<int> findArray(std::vector<int>& pref)
	{
		std::vector<int> answer(pref.size());

		answer.reserve;
		answer[0] = pref[0];

		for (int i = 1; i < pref.size(); i++)
		{
			answer[i] = pref[i] ^ pref[i - 1];
		}

		return answer;
	}
};

int main()
{
	Solution a;
	std::vector<int> b = { 5,2,0,3,1 };
	a.findArray(b);
	return 0;
}