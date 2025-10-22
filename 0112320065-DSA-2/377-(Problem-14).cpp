#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int combinationSum4(vector<int>& inputNumbers, int targetValue)

     {

        vector<unsigned long long> combinationCount(targetValue + 1, 0);


        combinationCount[0] = 1;


        for (int currentTarget = 1; currentTarget <= targetValue; ++currentTarget)

            {

            for (int number : inputNumbers)

             {

                if (currentTarget >= number)

                {

                    combinationCount[currentTarget] += combinationCount[currentTarget - number];
                }
            }
        }


        return static_cast<int>(combinationCount[targetValue]);
    }
};


int main()

 {
    int numberOfElements, targetValue;
    cout << "Enter number of elements: ";
    cin >> numberOfElements;

    vector<int> inputNumbers(numberOfElements);
    cout << "Enter the elements: ";


    for (int i = 0; i < numberOfElements; ++i)

        {
        cin >> inputNumbers[i];
    }

    cout << "Enter target value: ";
    cin >> targetValue;

    Solution solution;
    int result = solution.combinationSum4(inputNumbers, targetValue);

    cout << "Total possible combinations to form " << targetValue << " = " << result << endl;
    return 0;
}

