#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
	int w = 0;
	int len = truck_weights.size();
	int car = len - 1;

	vector<int> truck_time;
	for(int i = 0;i<len;i++)
		truck_time.push_back(-1);

	reverse(truck_weights.begin(),truck_weights.end());

	while(len)
	{	
		if(truck_time[len-1] == bridge_length){
			w -= truck_weights[len-1];

			truck_time.pop_back();
			truck_weights.pop_back();
			--len;
		}

		if (car > -1) {
			if (w + truck_weights[car] <= weight) {
				truck_time[car] = 0;
				w += truck_weights[car];
				--car;
			}
		}

		for(int i = 0;i<truck_time.size();i++)
			if(truck_time[i] > -1)
				truck_time[i]++;

		++answer;
	}
    return answer;
}
