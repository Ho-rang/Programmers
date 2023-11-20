#include <vector>
#include <string>

class Solution 
{
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel)
    {
        std::vector<int> truck(3);

        for (int i = garbage.size() - 1; i >= 0; i--)
        {
            for (const auto& g : garbage)
            {
                for (const auto& mgp : g)
                {
                    switch (mgp)
                    {
                    case 'M':
                        truck[0]++;
                        break;
                    case 'G':
                        truck[1]++;
                        break;
                    case 'P':
                        truck[2]++;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
};