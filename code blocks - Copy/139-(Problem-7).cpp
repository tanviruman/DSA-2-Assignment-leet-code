#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)

    {

        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());

        int strLength = s.size();

        vector<bool> dp(strLength + 1, false);

        dp[0] = true;


        for (int i = 1; i <= strLength; i++)

            {
            for (int j = 0; j < i; j++) {

                if (dp[j] && dictionary.count(s.substr(j, i - j)))

                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[strLength];
    }
};

int main()

 {
    Solution solution;


    string s = "leetcode";

    vector<string> wordDict = {"leet", "code"};


    bool result = solution.wordBreak(s, wordDict);


    cout << (result ? "True" : "False") << endl;

    return 0;
}

