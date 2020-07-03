#include <string>
#include <vector>

using namespace std;

//피보나치
int solution(int n) {
    int answer = 0;
    int a = 1;
	int b = 2;
	int c;
	
    if(n < 3){
		answer = n;
		return answer;
	}

    for(int i = 3; i <= n; i++) {
        c = b; 
		b = (a + b) % 1000000007; 
		a = c;
    }
	answer = b ;
    return answer;
}
