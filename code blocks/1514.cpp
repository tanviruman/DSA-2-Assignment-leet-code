#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxProbability(int nodeCount, vector<vector<int>>& edges, vector<double>& successProbability, int startNode, int endNode)

    {

        vector<vector<pair<int, double>>> adjacencyList(nodeCount);

        for (int i = 0; i < edges.size(); i++)

            {
            int fromNode = edges[i][0];
            int toNode = edges[i][1];
            double edgeProbability = successProbability[i];
            adjacencyList[fromNode].push_back({toNode, edgeProbability});
            adjacencyList[toNode].push_back({fromNode, edgeProbability});
        }


        priority_queue<pair<double, int>> maxHeap;
    vector<double> bestProbability(nodeCount, 0.0);

    bestProbability[startNode] = 1.0;
        maxHeap.push({1.0, startNode});


        while (!maxHeap.empty())

            {
            auto [currentProbability, currentNode] = maxHeap.top();
            maxHeap.pop();

            if (currentNode == endNode)
                return currentProbability;


            if (currentProbability < bestProbability[currentNode])
                continue;

            for (auto& neighbor : adjacencyList[currentNode])


                {
                int nextNode = neighbor.first;
                double edgeProbability = neighbor.second;
                double newProbability = currentProbability * edgeProbability;


                if (newProbability > bestProbability[nextNode])


                    {
                    bestProbability[nextNode] = newProbability;
                    maxHeap.push({newProbability, nextNode});
                }
            }
        }


        return 0.0;
    }
};

int main()



 {
    Solution solution;


    int nodeCount = 3;
    vector<vector<int>> edges =

    {
        {0, 1},
        {1, 2},
        {0, 2}
    };
    vector<double> successProbability = {0.5, 0.5, 0.2};
    int startNode = 0;
    int endNode = 2;

    double result = solution.maxProbability(nodeCount, edges, successProbability, startNode, endNode);

    cout << "Maximum Probability from " << startNode << " to " << endNode << " is: " << result << endl;

    return 0;
}

