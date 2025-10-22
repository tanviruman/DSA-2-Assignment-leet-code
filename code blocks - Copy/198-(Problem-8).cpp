#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(const vector<int>& houseValues)
    {
        int previousMaxRobbery = 0;
        int currentMaxRobbery = 0;
        for (int currentHouseValue : houseValues)

            {

            int newMaxRobbery = max(currentMaxRobbery, previousMaxRobbery + currentHouseValue);
            previousMaxRobbery = currentMaxRobbery;
            currentMaxRobbery = newMaxRobbery;
        }

        return currentMaxRobbery;
    }
};

int main()
{
    Solution solutionInstance;
    int numberOfHouses;
    cout << "Enter number of houses: ";
    cin >> numberOfHouses;

    vector<int> houseValues(numberOfHouses);
    cout << "Enter money in each house: ";

    for (int i = 0; i < numberOfHouses; ++i)
        {
        cin >> houseValues[i];

    }

    int maximumMoneyRobbed = solutionInstance.rob(houseValues);
    cout << "Maximum money that can be robbed: " << maximumMoneyRobbed << endl;

    return 0;
}
