class Solution {
    int robRange(vector<int>& nums, int s, int e) {
    int prev = 0, curr = 0;
    for (int i = s; i < e; ++i) {
        int temp = max (curr, prev + nums[i]);
        prev = curr;
        curr = temp;
    }    
    return curr;
    }
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max (robRange (nums, 0, n - 1), robRange (nums, 1, n));
    }
};