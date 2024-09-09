#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int r1, int r2)
{
	long long answer = 0;
	answer -= r2 - r1 + 1;
	long long R1 = pow(r1, 2);
	long long R2 = pow(r2, 2);

	for (int x = 0; x <= r2; x++)
	{
		long long xx = pow(x, 2);
		int t2 = sqrt(R2 - xx);  // r2의 원 위 y 좌표 계산

		int t1;
		if (x < r1) 
		{
			double td = sqrt(R1 - xx);
			int ti = sqrt(R1 - xx);
			t1 = td > (double)ti ? ti + 1 : ti;
		}
		else 
		{
			t1 = 0; 
		}

		answer += t2 - t1 + 1;
	}

	answer *= 4;

	return answer;
}