class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxindex = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxindex) return false;
            maxindex = max (maxindex, i + nums[i]);
            if (maxindex >= n - 1) return true;
        } 
        return true;
    }
};