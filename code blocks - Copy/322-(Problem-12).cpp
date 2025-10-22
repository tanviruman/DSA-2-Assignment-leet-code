#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coinValues, int targetAmount)

     {
        if (targetAmount == 0)
            return 0;


        vector<int> minCoins(targetAmount + 1, targetAmount + 1);
        minCoins[0] = 0;


        for (int coin : coinValues)


            {
            for (int currentAmount = coin; currentAmount <= targetAmount; currentAmount++)


             {
                minCoins[currentAmount] = min(minCoins[currentAmount], minCoins[currentAmount - coin] + 1);
            }
        }


        return (minCoins[targetAmount] > targetAmount) ? -1 : minCoins[targetAmount];
    }
};

int main()

 {
    Solution solution;


    vector<int> coinValues = {1, 2, 5};


    int targetAmount = 11;

    int result = solution.coinChange(coinValues, targetAmount);

    cout << "Minimum number of coins needed: " << result << endl;

    return 0;
}
