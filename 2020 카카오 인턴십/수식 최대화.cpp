#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
	long long answer = 0;

	vector<char> oper_list = { '*','+','-' }; // next_permutation 사용시 정렬 되어있어야함.
	vector<char> oper;
	vector<long long> number;
	string num = "";

	for (int i = 0 ;i < expression.size(); i++)
	{
		if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-')
		{
			oper.push_back(expression[i]);
			number.push_back(atoi(num.c_str()));
			num = "";
		}
		else 
			num += expression[i];
	}
	number.push_back(atoi(num.c_str()));

	do {
		vector<char> temp_oper = oper;
		vector<long long> temp_number = number;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < temp_oper.size(); j++)
				if (temp_oper[j] == oper_list[i])
				{
					if (oper_list[i] == '+')
						temp_number[j] += temp_number[j + 1];

					else if (oper_list[i] == '-')
						temp_number[j] -= temp_number[j + 1];

					else if (oper_list[i] == '*')
						temp_number[j] *= temp_number[j + 1];

					temp_number.erase(temp_number.begin() + j + 1);
					temp_oper.erase(temp_oper.begin() + j);
					j--;
				}

		if (temp_number.front() < 0)
			temp_number.front() *= -1;

		if (answer < temp_number.front())
			answer = temp_number.front();

	} while (next_permutation(oper_list.begin(), oper_list.end()));

	return answer;
}
