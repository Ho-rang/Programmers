#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;

	int p = 0;
	int y = 0;
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
		if (s[i] == 'P')
			p++;
		else if (s[i] == 'Y')
			y++;
	}

	answer = p == y ? true : false;
	return answer;
}
