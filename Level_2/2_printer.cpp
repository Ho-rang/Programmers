#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> qq;
    
    for(int i = 0; i < priorities.size(); i++){
        qq.push(priorities[i]);
    }
    
    while(true){
        if(qq.front() != *max_element(priorities.begin(),priorities.end())){
            qq.push(qq.front());
            qq.pop();
            
            location--;
        } else{
            if(location < 0){
                location += priorities.size();
            }
            break;
        }
    }
    
    while(true){
        if(location == 0){
            return answer + 1;
        } else{
            qq.pop();
            location--;
            answer++;
        }
    }
}
