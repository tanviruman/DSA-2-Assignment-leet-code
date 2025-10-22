#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int findTheCity(int cityCount, vector<vector<int>>& edges, int distanceThreshold)


     {
        const int INF = 1e9;
        vector<vector<int>> distance(cityCount, vector<int>(cityCount, INF));


        for (int i = 0; i < cityCount; i++)
            distance[i][i] = 0;


        for (auto &edge : edges)

            {
            int fromCity = edge[0];
            int toCity = edge[1];
            int weight = edge[2];
            distance[fromCity][toCity] = weight;
            distance[toCity][fromCity] = weight;
        }


        for (int viaCity = 0; viaCity < cityCount; viaCity++)

            {
            for (int fromCity = 0; fromCity < cityCount; fromCity++)
            {
                for (int toCity = 0; toCity < cityCount; toCity++)

                 {
                    if (distance[fromCity][viaCity] + distance[viaCity][toCity] < distance[fromCity][toCity])


                     {
                        distance[fromCity][toCity] = distance[fromCity][viaCity] + distance[viaCity][toCity];
                    }
                }
            }
        }

        int minReachableCities = cityCount + 1;
        int resultCity = -1;


        for (int currentCity = 0; currentCity < cityCount; currentCity++)


            {
            int reachableCount = 0;
            for (int otherCity = 0; otherCity < cityCount; otherCity++)


             {
                if (currentCity != otherCity && distance[currentCity][otherCity] <= distanceThreshold)

                 {
                    reachableCount++;
                }
            }


            if (reachableCount <= minReachableCities)


                {
                minReachableCities = reachableCount;
                resultCity = currentCity;
            }
        }

        return resultCity;
    }
};

int main()

{
    Solution solution;


    int cityCount = 4;
    vector<vector<int>> edges =

    {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    int distanceThreshold = 4;


    int city = solution.findTheCity(cityCount, edges, distanceThreshold);


    cout << "City with the smallest number of neighbors within threshold: " << city << endl;

    return 0;
}

