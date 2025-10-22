#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:

    int maxProfit(const vector<int>& dailyPrices) {

        int lowestPriceSoFar = std::numeric_limits<int>::max();

        int maximumProfitSoFar = 0;


        for (int currentPrice : dailyPrices)
            {


            if (currentPrice < lowestPriceSoFar)
            {
                lowestPriceSoFar = currentPrice;
            }

            else if (currentPrice - lowestPriceSoFar > maximumProfitSoFar)
                {
                maximumProfitSoFar = currentPrice - lowestPriceSoFar;
            }
        }


        return maximumProfitSoFar;
    }
};

int main()
{
    Solution solutionInstance;
    vector<int> inputPrices;
    int n;

    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter the daily stock prices separated by spaces: ";
    inputPrices.resize(n);
    for (int i = 0; i < n; ++i)
        {
        cin >> inputPrices[i];
    }

    int bestProfit = solutionInstance.maxProfit(inputPrices);
    cout << "Maximum profit achievable: " << bestProfit << endl;

    return 0;
}
