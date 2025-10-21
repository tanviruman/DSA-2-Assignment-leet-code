class Solution {
public:
    int rob(vector<int>& nums) {
        int p = 0, c = 0;
        for (int n : nums) {
            int t = max (c, p + n);
            p = c;
            c = t;
        }
        return c;
    }
};