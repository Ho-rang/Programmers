#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();

    for (int i = 0; i < skill_trees.size(); i++)
    {
        vector<int> index;
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            for(int z = 0;z < skill.size();z++)
            {
                if(skill_trees[i][j] == skill[z])
                {
                    index.push_back(z);
                    continue;
                }
            }
        }
        int num = 0;
        for (int j : index)
        {
            if (num != j)
            {
                answer--;
                break;
            }
            else
                num++;
        }
    }
    return answer;
}
