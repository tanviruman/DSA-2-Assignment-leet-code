#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int uniquePaths(int totalRows, int totalColumns)
     {

        vector<int> pathCount(totalColumns, 1);


        for (int currentRow = 1; currentRow < totalRows; ++currentRow)

            {

            for (int currentColumn = 1; currentColumn < totalColumns; ++currentColumn)


             {

                pathCount[currentColumn] += pathCount[currentColumn - 1];
            }
        }


        return pathCount[totalColumns - 1];
    }
};


int main()

{
    int totalRows, totalColumns;

    cout << "Enter number of rows (m): ";
    cin >> totalRows;
    cout << "Enter number of columns (n): ";
    cin >> totalColumns;

    Solution solution;

    int totalUniquePaths = solution.uniquePaths(totalRows, totalColumns);

    cout << "Total unique paths in a " << totalRows << "x" << totalColumns << " grid: "

         << totalUniquePaths << endl;

    return 0;
}

