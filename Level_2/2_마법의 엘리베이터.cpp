#include <string>
#include <vector>

using namespace std;

int solution(int storey)
{
	int answer = 0;

	while (storey > 0)
	{
		int temp = storey % 10;
		storey /= 10;

		if (temp > 5)
		{
			storey += 1;
			answer += 10 - temp;
		}
		else if (temp < 5)
		{
			answer += temp;
		}
		else
		{
			int carry = storey % 10;
			if (carry >= 5)
				storey += 1;

			answer += temp;
		}

	}

	return answer;
}