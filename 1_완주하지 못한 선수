#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < participant.size(); i++) //completion -> participant 굳이 안빠져나와도 됨
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
}
