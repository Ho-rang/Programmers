//그냥 3진법임

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int a;
    while(n > 0){
        a = n % 3;
        n = (n - 1) / 3;
        
        if(a == 0){
            answer = '4' + answer;
        }else if(a == 1){
            answer = '1' + answer;
        }else if(a == 2){
            answer = '2' + answer;
        }
        
    }
    return answer;
}
