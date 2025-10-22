#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& numbers)

     {
        vector<int> increasingSequence;

        for (int currentNumber : numbers)

            {

            auto position = lower_bound(increasingSequence.begin(), increasingSequence.end(), currentNumber);

            if (position == increasingSequence.end())


                {

                increasingSequence.push_back(currentNumber);
            }
            else

            {


                *position = currentNumber;
            }
        }

        return increasingSequence.size();
    }
};

int main()

{
    Solution solution;


    vector<int> numbers = {10, 9, 2, 5, 3, 7, 101, 18};

    int result = solution.lengthOfLIS(numbers);

    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}
