#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	string alphabet[] =
	{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	for (int i = 0; i < s.size(); i++)
	{
		answer *= 10;

		if (s[i] >= '0' && s[i] <= '9')
		{
			answer += s[i] - '0';
			continue;
		}
		
		for (int j = 0; j < 10 ;j++)
		{
			if (s[i] == alphabet[j][0] && s[i + 1] == alphabet[j][1])
			{
				answer += j;
				i += alphabet[j].size() - 1;
			}
		}
	}

	return answer;
}
