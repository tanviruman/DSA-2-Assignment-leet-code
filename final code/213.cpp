#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:

    int robRange(const vector<int>& houseValues, int startIndex, int endIndex)
     {
        int previousMaxRobbery = 0;
        int currentMaxRobbery = 0;

        for (int i = startIndex; i < endIndex; ++i)

            {
            int newMaxRobbery = max(currentMaxRobbery, previousMaxRobbery + houseValues[i]);
            previousMaxRobbery = currentMaxRobbery;
            currentMaxRobbery = newMaxRobbery;
        }

        return currentMaxRobbery;
    }

public:
    int rob(const vector<int>& houseValues)

    {
        int numberOfHouses = houseValues.size();


        if (numberOfHouses == 1)

            {
            return houseValues[0];
        }


        int maxRobberyExcludingLast = robRange(houseValues, 0, numberOfHouses - 1);


        int maxRobberyExcludingFirst = robRange(houseValues, 1, numberOfHouses);


        return max(maxRobberyExcludingLast, maxRobberyExcludingFirst);
    }
};

int main() {
    Solution solutionInstance;
    int numberOfHouses;
    cout << "Enter number of houses (in a circle): ";
    cin >> numberOfHouses;

    vector<int> houseValues(numberOfHouses);
    cout << "Enter the money in each house: ";

    for (int i = 0; i < numberOfHouses; ++i)

        {
        cin >> houseValues[i];
    }

    int maximumMoneyRobbed = solutionInstance.rob(houseValues);
    cout << "Maximum money that can be robbed (circular houses): "
         << maximumMoneyRobbed << endl;

    return 0;
}
