
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution 
{
public:
	string reverseWords(string s) 
	{
		std::istringstream iss(s);
		std::string answer = "";

		std::string word;
		while (iss >> word) 
		{
			std::reverse(word.begin(), word.end());
			answer += word;
			answer += ' ';
		}

		answer.pop_back();

		return answer;
	}
};

int main()
{

	return 0;
}