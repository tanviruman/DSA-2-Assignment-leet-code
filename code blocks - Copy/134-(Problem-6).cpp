#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gasAmounts, const vector<int>& travelCosts)
     {
        int stationCount = gasAmounts.size();

        int totalGasAvailable = 0;

        int totalTravelCost = 0;

        int currentTank = 0;

        int candidateStartIndex = 0;

        for (int stationIndex = 0; stationIndex < stationCount; ++stationIndex)
            {
            totalGasAvailable += gasAmounts[stationIndex];
            totalTravelCost += travelCosts[stationIndex];

            currentTank += gasAmounts[stationIndex] - travelCosts[stationIndex];


            if (currentTank < 0)
                {
                candidateStartIndex = stationIndex + 1;
                currentTank = 0;
            }
        }


        if (totalGasAvailable < totalTravelCost)

            {
            return -1;
        }


        return candidateStartIndex;
    }
};

int main()
 {
    Solution solutionInstance;
    int n;

    cout << "Enter number of gas stations: ";
    cin >> n;

    vector<int> gasAmounts(n), travelCosts(n);
    cout << "Enter gas amounts for each station:\n";
    for (int i = 0; i < n; ++i) {
        cin >> gasAmounts[i];
    }
    cout << "Enter travel costs for each station:\n";
    for (int i = 0; i < n; ++i) {
        cin >> travelCosts[i];
    }

    int startingStation = solutionInstance.canCompleteCircuit(gasAmounts, travelCosts);
    if (startingStation >= 0)

        {
        cout << "You can complete the circuit starting at station index: " << startingStation << endl;
    } else {
        cout << "It is impossible to complete the circuit from any station." << endl;
    }

    return 0;
}

