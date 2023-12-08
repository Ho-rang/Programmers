class Solution
{
public:
	int totalMoney(int n)
	{
		int result = 0;

		int week = n / 7;
		int day = n % 7;

		result += ((week * (week - 1)) / 2) * 7;
		result += 28 * week;

		result += ((day * (day + 1)) / 2) + week * day;

		return result;
	}
};