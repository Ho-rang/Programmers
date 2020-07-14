#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &x, string &y)
{
    return (x+y) > (y+x); 
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    string temp="";

    for(int i : numbers)
    {
        s.push_back(to_string(i));
    }

    sort(s.begin(),s.end(),compare);

    for(string i : s)
    {
        answer += i;
    }
    
    if(s[0] == "0")
    {
        return "0";    
    }

    return answer;
}
