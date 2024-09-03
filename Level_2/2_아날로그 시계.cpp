#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2)
{
	int answer = -1;

	auto GetCountClockZeroTo = [](int h, int m, int s)
		{
			int result = -1;

			{
				const int hDegree = static_cast<int>(h * 30 + m * 0.5 + s * 0.5 / 60) % 360;
				const int mDegree = static_cast<int>(m * 6 + s * 0.1) % 360;
				const int sDegree = s * 6;


				if (sDegree >= mDegree)
					result++;
				if (mDegree >= hDegree)
					result++;
			}

			result += (h * 60 + m) * 2;
			result -= h;

			if (h >= 12)
				result -= 2;

			return result;
		};

	answer = GetCountClockZeroTo(h2, m2, s2) - GetCountClockZeroTo(h1, m1, s1);

	if ((h1 == 0 || h1 == 12) && (m1 == 0) && (s1 == 0))
		answer++;

	return answer;
}