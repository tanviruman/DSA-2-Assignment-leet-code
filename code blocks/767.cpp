#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string inputString)

     {
        unordered_map<char, int> characterFrequency;
        for (char currentCharacter : inputString)

            {
            characterFrequency[currentCharacter]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto &entry : characterFrequency)

            {
            maxHeap.push({entry.second, entry.first});
        }

        string resultString = "";

        while (maxHeap.size() > 1)

            {
            pair<int, char> firstEntry = maxHeap.top();
            maxHeap.pop();
            pair<int, char> secondEntry = maxHeap.top();
            maxHeap.pop();

            resultString += firstEntry.second;
            resultString += secondEntry.second;

            if (--firstEntry.first > 0) {
                maxHeap.push(firstEntry);
            }
            if (--secondEntry.first > 0) {
                maxHeap.push(secondEntry);
            }
        }

        if (!maxHeap.empty()) {
            pair<int, char> lastEntry = maxHeap.top();
            if (lastEntry.first > 1) {
                return "";
            }
            resultString += lastEntry.second;
        }

        return resultString;
    }
};

int main()


 {
    Solution solution;
    string input = "aab";
    cout << solution.reorganizeString(input) << endl;
    input = "aaab";
    cout << solution.reorganizeString(input) << endl;

    return 0;
}
