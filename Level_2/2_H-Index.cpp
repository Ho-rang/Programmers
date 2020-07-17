#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end());
	
	int h = 0;
    while(true){
        int count = 0;

        for(int j : citations)
			if (h <= j)
				count++;
			
		if (count >= h) {
			answer = h;
		}
		h++;

		if (h > citations[citations.size() - 1]) {
			break;
		}
    }

    return answer;
}
