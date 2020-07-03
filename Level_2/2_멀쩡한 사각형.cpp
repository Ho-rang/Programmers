#include <algorithm>


using namespace std;

int getgcd(int a, int b)    //유클리드 호제법
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}


long long solution(int w, int h)
{
	long long answer = (long)w*h; //int 범위 초과
	int gcd = getgcd(w, h);
	
	answer -= w + h - gcd;
	
	return answer;
}
