#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {

    if (n <= 2) return n;

        int st1 = 1, st2 = 2;

        for (int i = 3; i <= n; ++i)
            {
            int ways = st1 + st2;

            st1 = st2;
            st2 = ways;
        }


        return st2;
    }
};

int main()
{

    Solution sol;
    int n;
    cout << "Enter number of stairs: ";

    cin >> n;
    int result = sol.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << result << endl;
    return 0;
}
