#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    bool decimal[10000001] = { false };
    
    for (int i = 2; i <= N; i++) {         //2부터 N까지
        if (!decimal[i])                   //false 일때 더함
            answer += i;
        
        for (int j = i; j <= N; j += i) {  //N까지 i의 모든 배수 true
            decimal[j] = true;
        }
    }
    return answer;
}
