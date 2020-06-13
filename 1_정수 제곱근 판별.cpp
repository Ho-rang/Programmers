#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long num = sqrt(n);
    if(n == pow(num,2))
        answer = pow(num+1,2);
    else
        answer = -1;
    
    
    return answer;
}
