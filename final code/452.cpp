#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& balloonIntervals)
     {
        if (balloonIntervals.empty())
            return 0;


        sort(balloonIntervals.begin(), balloonIntervals.end());

        int arrowCount = 1;
        int currentEnd = balloonIntervals[0][1];

        for (int i = 1; i < balloonIntervals.size(); i++)

            {
            int balloonStart = balloonIntervals[i][0];
            int balloonEnd = balloonIntervals[i][1];

            if (balloonStart > currentEnd) {
                arrowCount++;
                currentEnd = balloonEnd;
            }

            else

                {

                currentEnd = min(currentEnd, balloonEnd);
            }
        }

        return arrowCount;
    }
};

int main()

{
    Solution solution;


    vector<vector<int>> balloonIntervals =


    {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    int result = solution.findMinArrowShots(balloonIntervals);

    cout << "Minimum number of arrows needed: " << result << endl;

    return 0;
}

