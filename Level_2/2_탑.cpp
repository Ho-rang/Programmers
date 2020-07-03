#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
	int n = heights.size();

	for (int i = heights.size() - 1; i > 0; i--)
	{
		int j = n-1;
		while (1)
		{
			if (j < 0) {
				answer.push_back(0);
				n--;
				break;
			}
			if (heights[i] < heights[j])
			{
				answer.push_back(j + 1);
				n--;
				break;
			}
			j--;
		}
	}
    answer.push_back(0);
	reverse(answer.begin(),answer.end());
	return answer;
}
