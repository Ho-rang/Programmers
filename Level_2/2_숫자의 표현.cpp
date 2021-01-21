#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int repeat = n / 2;

    for (int i = 1; i <= repeat; i++)
    {
        int max = 0;
        int j = i;

        while (max <= n)
        {
            if (max == n)
            {
                answer++;
                break;
            }
            
            max += j++;
        }
    }

    return answer;
}
