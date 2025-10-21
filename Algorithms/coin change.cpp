#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 

int minCoins(int coins[], int m, int amount, int dp[][100]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= amount; j++) {
            if (i == 0) dp[i][j] = (j == 0 ? 0 : INF);
            else dp[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= amount; j++) {
            if (coins[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }

    return dp[m][amount];
}

void findCoins(int coins[], int m, int amount, int dp[][100]) {
    int i = m, j = amount;
    cout << "Coins used: ";
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            cout << coins[i-1] << " ";
            j -= coins[i-1];
        }
    }
    cout << endl;
}

int main() {
    int coins[] = {1, 3, 4}; 
    int m = sizeof(coins)/sizeof(coins[0]);
    int amount = 6;

    int dp[100][100];

    int result = minCoins(coins, m, amount, dp);

    if (result >= INF)
        cout << "No solution possible" << endl;
    else {
        cout << "Minimum coins needed = " << result << endl;
        findCoins(coins, m, amount, dp);
    }

    return 0;
}
