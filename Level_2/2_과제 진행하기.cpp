#include <string>
#include <vector>
#include <algorithm>
#include <stack>

bool compare(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
	int hourA = std::stoi(a[1].substr(0, 2));
	int hourB = std::stoi(b[1].substr(0, 2));

	if (hourA == hourB)
	{
		return std::stoi(a[1].substr(3, 2)) < std::stoi(b[1].substr(3, 2));
	}
	else
	{
		return (hourA < hourB);
	}
}

inline int TimeToMinute(const std::string& str)
{
	return (std::stoi(str.substr(0, 2)) * 60) + std::stoi(str.substr(3, 2));
}

std::vector<std::string> solution(std::vector<std::vector<std::string>> plans)
{
	std::vector<std::string> answer;

	std::stack<std::vector<std::string>> buffer;

	std::sort(plans.begin(), plans.end(), compare);

	while (!plans.empty() || !buffer.empty())
	{
		if (plans.size() == 1)
		{
			answer.push_back(plans.front()[0]);
			plans.pop_back();

			while (!buffer.empty())
			{
				answer.push_back(buffer.top()[0]);
				buffer.pop();
			}

			continue;
		}

		// 다음 작업까지의 시간 텀
		int time = TimeToMinute(plans[1][1]) - TimeToMinute(plans[0][1]);

		// 작업 시간
		int playTime = std::stoi(plans[0][2]);

		if (playTime > time)
		{
			playTime -= time;
			plans[0][2] = std::to_string(playTime);
			buffer.push(plans[0]);
		}
		else if (playTime <= time)
		{
			answer.push_back(plans[0][0]);
			time -= playTime;

			while (!buffer.empty() && time > 0)
			{
				int bufferTime = std::stoi(buffer.top()[2]);
				if (bufferTime - time <= 0)
				{
					time -= bufferTime;
					answer.push_back(buffer.top()[0]);
					buffer.pop();
				}
				else
				{
					bufferTime -= time;
					buffer.top()[2] = std::to_string(bufferTime);
					break;
				}
			}
		}

		plans.erase(plans.begin());
	}

	return answer;
}

void main()
{
	std::vector<std::vector<std::string>> v = {
	{"science", "12:40", "50"},
	{"music", "12:20", "40"},
	{"history", "14:00", "30"},
	{"computer", "12:30", "100"}
	};
	solution(v);

}