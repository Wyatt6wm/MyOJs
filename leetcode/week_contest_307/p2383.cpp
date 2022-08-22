#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int hours = 0;

        // 计算提升energy需要训练的小时数
        int engSum = 0;
        for (int eng : energy)
            engSum += eng;
        if (initialEnergy <= engSum)
            hours += engSum - initialEnergy + 1; // 要求严格大于，因此+1

        // 计算提升experence需要训练的小时数
        int nowExp = initialExperience;
        for (int exp : experience)
        {
            if (nowExp <= exp)
            {
                hours += exp - nowExp + 1; // 要求严格大于，因此+1
                nowExp += exp - nowExp + 1;
            }
            nowExp += exp;
        }

        return hours;
    }
};

int main()
{
    vector<int> energy1 = {1, 4, 3, 2};
    vector<int> experence1 = {2, 6, 3, 1};
    vector<int> energy2 = {1};
    vector<int> experence2 = {3};
    Solution solution;
    cout << solution.minNumberOfHours(5, 3, energy1, experence1) << endl; // 样例1
    cout << solution.minNumberOfHours(2, 4, energy2, experence2) << endl; // 样例2
    return 0;
}