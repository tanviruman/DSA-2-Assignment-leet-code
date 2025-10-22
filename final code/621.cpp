#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int cooldownPeriod)

     {


        if (cooldownPeriod == 0)

            {
            return tasks.size();
        }

        array<int, 26> taskFrequencies = {0};



        for (char task : tasks)

            {
            taskFrequencies[task - 'A']++;
        }



        int maxFrequency = *max_element(taskFrequencies.begin(), taskFrequencies.end());



        int maxFrequencyTaskCount = 0;
        for (int frequency : taskFrequencies)
            {
            if (frequency == maxFrequency)
            {
                maxFrequencyTaskCount++;
            }
        }



        int minRequiredSlots = (maxFrequency - 1) * (cooldownPeriod + 1) + maxFrequencyTaskCount;



        return max(minRequiredSlots, (int)tasks.size());
    }
};

int main()

 {
    Solution solution;



    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int cooldownPeriod = 2;

    int result = solution.leastInterval(tasks, cooldownPeriod);

    cout << "Minimum time to finish all tasks: " << result << endl;

    return 0;
}

