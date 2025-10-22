#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int numberOfCities,
                          vector<vector<int>>& flightRoutes,
                          int sourceCity,
                          int destinationCity,
                          int maximumStops)

                          {
        vector<int> minimumCostToCity(numberOfCities, INT_MAX);
        minimumCostToCity[sourceCity] = 0;

        for (int i = 0; i <= maximumStops; i++)
            {
            vector<int> costSnapshot = minimumCostToCity;

            for (auto& route : flightRoutes)

                {
                int fromCity   = route[0];
                int toCity     = route[1];
                int flightCost = route[2];

                if (minimumCostToCity[fromCity] != INT_MAX &&
                    minimumCostToCity[fromCity] + flightCost < costSnapshot[toCity])

                     {
                    costSnapshot[toCity] = minimumCostToCity[fromCity] + flightCost;
                }
            }

            minimumCostToCity = costSnapshot;
        }

        return (minimumCostToCity[destinationCity] == INT_MAX)
            ? -1
            : minimumCostToCity[destinationCity];
    }
};

int main() {
    Solution solution;

    int numberOfCities = 4;
    vector<vector<int>> flightRoutes = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int sourceCity      = 0;
    int destinationCity = 2;
    int maximumStops    = 1;

    cout << solution.findCheapestPrice(numberOfCities,
                                       flightRoutes,

                                       sourceCity,
                                       destinationCity,
                                       maximumStops)
         << endl;
    return 0;
}
