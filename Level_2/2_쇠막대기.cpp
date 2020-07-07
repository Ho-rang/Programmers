#include <string>
#include <vector>

using namespace std;

int solution(string arrangement)
{
    int answer = 0;

    int stick = 1; //시작은 무조건 여는 괄호 

    for (int i = 1; i < arrangement.length(); i++)
    {
        char c = arrangement[i];
        if (c == '(')
        {
            stick++;
        }
        else
        {
            stick--;

            char h = arrangement[i - 1];
            if (h == '(')
            {
                answer += stick;
            }
            else
            {
                answer++;
            }
        }
    }

    return answer;
}
