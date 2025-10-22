#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    int numDecodings(const string& encodedString)
    {

        int lengthOfString = encodedString.size();

        if (lengthOfString == 0 || encodedString[0] == '0')
            {
            return 0;
        }

        int waysTwoBack = 1;

        int waysOneBack = 1;

        for (int currentIndex = 1; currentIndex < lengthOfString; ++currentIndex)
            {

            int waysCurrent = 0;

            if (encodedString[currentIndex] != '0')
                {
                waysCurrent += waysOneBack;
            }


        int twoDigitValue = (encodedString[currentIndex - 1] - '0') * 10

                    + (encodedString[currentIndex] - '0');
        if (twoDigitValue >= 10 && twoDigitValue <= 26)

            {
                waysCurrent += waysTwoBack;
            }


            waysTwoBack = waysOneBack;
            waysOneBack = waysCurrent;


        }

        return waysOneBack;
    }
};

int main()
{
    Solution solutionInstance;
    string inputString;
    cout << "Enter an encoded string (digits only): ";
    cin >> inputString;

    int numberOfWays = solutionInstance.numDecodings(inputString);
    cout << "Number of ways to decode \"" << inputString << "\": "
         << numberOfWays << endl;

    return 0;
}

