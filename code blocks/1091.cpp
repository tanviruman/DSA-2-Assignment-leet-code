#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)

    {
        int gridSize = grid.size();


        if (grid[0][0] == 1 || grid[gridSize - 1][gridSize - 1] == 1)
            return -1;


        vector<vector<int>> directions =

        {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        queue<pair<int, int>> bfsQueue;
        bfsQueue.push({0, 0});
        grid[0][0] = 1;

        int pathLength = 1;


        while (!bfsQueue.empty())

            {
            int currentLevelSize = bfsQueue.size();

            while (currentLevelSize--)

                {
                auto [currentRow, currentCol] = bfsQueue.front();
                bfsQueue.pop();


                if (currentRow == gridSize - 1 && currentCol == gridSize - 1)
                    return pathLength;


                for (auto& direction : directions)

                    {
                    int nextRow = currentRow + direction[0];
                    int nextCol = currentCol + direction[1];


                    if (nextRow >= 0 && nextCol >= 0 && nextRow < gridSize && nextCol < gridSize && grid[nextRow][nextCol] == 0)


                        {
                        bfsQueue.push({nextRow, nextCol});
                        grid[nextRow][nextCol] = 1;
                    }
                }
            }
            pathLength++;
        }



        return -1;
    }
};

int main()


{
    Solution solution;



    vector<vector<int>> grid =

    {
        {0, 1},
        {1, 0}
    };

    int result = solution.shortestPathBinaryMatrix(grid);

    cout << "Shortest path length in binary matrix: " << result << endl;

    return 0;
}

