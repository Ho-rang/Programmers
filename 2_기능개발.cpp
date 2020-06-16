#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	int day = 0;

	reverse(progresses.begin(), progresses.end());
	reverse(speeds.begin(), speeds.end());

	while (!progresses.empty())
	{
		while (progresses.back() > 100)
		{
			progresses.pop_back();
			speeds.pop_back();
			day++;
			
			if(progresses.back() < 100){
				answer.push_back(day);
				day = 0;
			}
		}
		for (int i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}
	}
	return answer;
}
