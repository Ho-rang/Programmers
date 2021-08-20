#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++)
	{
		string convert;
    string temp = s.substr(0, i); 
    
		int count = 1;
		
		for (int j = i; j < s.size(); j += i)
		{
			if (temp == s.substr(j, i))
				count++;
			else
			{
				if (count > 1)
					convert += to_string(count);
				convert += temp;
				temp = s.substr(j, i);
				count = 1;
			}
		}

		if (count > 1)
			convert += to_string(count);

		convert += temp;
		if (answer > convert.size())
			answer = convert.size();
	}

	return answer;
}
