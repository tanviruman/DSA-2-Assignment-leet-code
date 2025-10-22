#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    int longestCommonSubsequence(string firstText, string secondText)

    {
        int firstTextLength = firstText.length();
        int secondTextLength = secondText.length();


        vector<vector<int>> longestSubsequenceTable(firstTextLength + 1, vector<int>(secondTextLength + 1, 0));


        for (int firstIndex = 1; firstIndex <= firstTextLength; ++firstIndex)

            {

            for (int secondIndex = 1; secondIndex <= secondTextLength; ++secondIndex)

             {
                if (firstText[firstIndex - 1] == secondText[secondIndex - 1])

                 {

                    longestSubsequenceTable[firstIndex][secondIndex] =
                        longestSubsequenceTable[firstIndex - 1][secondIndex - 1] + 1;
                }
        else

        {


                    longestSubsequenceTable[firstIndex][secondIndex] =
                        max(longestSubsequenceTable[firstIndex - 1][secondIndex],
                            longestSubsequenceTable[firstIndex][secondIndex - 1]);
                }
            }
        }


        return longestSubsequenceTable[firstTextLength][secondTextLength];
    }
};


int main() {
    string firstText, secondText;

    cout << "Enter first string: ";
    cin >> firstText;

    cout << "Enter second string: ";
    cin >> secondText;

    Solution solution;
    int longestLength = solution.longestCommonSubsequence(firstText, secondText);

    cout << "Length of the Longest Common Subsequence: " << longestLength << endl;

    return 0;
}

