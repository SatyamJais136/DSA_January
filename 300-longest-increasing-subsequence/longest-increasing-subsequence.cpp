class Solution {
public:
    int rec(int i, int prev, int n, vector<int> &nums, vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        //not take
        int ans = 0;
        int notTake = rec(i+1, prev, n, nums, dp);
        ans = max(ans, notTake);
        if(prev == -1 || nums[i] > nums[prev]){
            int take = 1 + rec(i+1, i, n, nums, dp);
            ans = max(ans, take);
        } 
        return dp[i][prev+1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return rec(0, -1, n, nums, dp);
    }
};