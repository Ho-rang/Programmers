#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool compare(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
	if (a[0] == b[0])
		return a[1] < b[1];

	else
		return a[0] < b[0];
}

bool compare2(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
	return a[1] < b[1];
}

int solution(std::vector<std::vector<std::string>> book_time)
{
	int answer = 0;

	std::sort(book_time.begin(), book_time.end(), compare);

	
	decltype(book_time) book_using;
	
	book_using.push_back(book_time.front());
	book_time.erase(book_time.begin());
	answer += 1;

	while (!book_time.empty())
	{
		bool check = false;
		for (auto& book : book_using)
		{
			int time = (std::stoi(book[1].substr(0, 2)) * 60) + std::stoi(book[1].substr(3, 2));

			int enterTime = (std::stoi(book_time.front()[0].substr(0, 2)) * 60) + std::stoi(book_time.front()[0].substr(3, 2));

			if (time + 10 <= enterTime)
			{
				check = true;
				book = book_time.front();
				book_time.erase(book_time.begin());
				break;
			}
		}

		if(!check)
		{
			std::cout << book_time.front()[0] << " : " << book_time.front()[1] << std::endl;
			answer += 1;
			book_using.push_back(book_time.front());
			book_time.erase(book_time.begin());
		}
	}

	return answer;
}

int main()
{
	std::cout << solution(
		{{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}}
	);
	return 0;
}