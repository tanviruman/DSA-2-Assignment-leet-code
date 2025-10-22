#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int obstacleEliminationLimit)
    {
        int rowCount = grid.size();
        int colCount = grid[0].size();


        if (rowCount == 1 && colCount == 1)
            return 0;

        queue<vector<int>> bfsQueue;
        bfsQueue.push({0, 0, 0});

        vector<vector<vector<bool>>> visited(
            rowCount,
            vector<vector<bool>>(colCount, vector<bool>(obstacleEliminationLimit + 1, false))
        );

        visited[0][0][0] = true;

        int steps = 0;
        vector<int> directionOffsets = {0, 1, 0, -1, 0};

        while (!bfsQueue.empty())

        {
            int currentLevelSize = bfsQueue.size();
            steps++;

            while (currentLevelSize--)

            {
                auto current = bfsQueue.front();
                bfsQueue.pop();

                int currentRow = current[0];
                int currentCol = current[1];
                int obstaclesUsed = current[2];

                for (int i = 0; i < 4; i++)

                {
                    int nextRow = currentRow + directionOffsets[i];
                    int nextCol = currentCol + directionOffsets[i + 1];


                    if (nextRow < 0 || nextCol < 0 || nextRow >= rowCount || nextCol >= colCount)
                        continue;

                    int nextObstaclesUsed = obstaclesUsed + grid[nextRow][nextCol];


                    if (nextObstaclesUsed <= obstacleEliminationLimit &&
                        !visited[nextRow][nextCol][nextObstaclesUsed]) {


                        if (nextRow == rowCount - 1 && nextCol == colCount - 1)
                            return steps;

                        visited[nextRow][nextCol][nextObstaclesUsed] = true;


                        bfsQueue.push({nextRow, nextCol, nextObstaclesUsed});
                    }
                }
            }
        }


        return -1;
    }
};

int main() {
    Solution solution;


    vector<vector<int>> grid =

    {
        {0, 0, 0},
        {1, 1, 0},
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 0}
    };

    int obstacleEliminationLimit = 1;

    int shortestPathLength = solution.shortestPath(grid, obstacleEliminationLimit);

    cout << "Shortest path length: " << shortestPathLength << endl;

    return 0;
}
