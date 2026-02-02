class Solution {
public:
    int rec(int i, int sum, int n, int total, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(i == n) return (sum == target) ? 1 : 0;
        if(dp[i][total+sum] != -1) return dp[i][total+sum];
        int positive = rec(i+1, sum + nums[i], n, total, target, nums, dp);
        int negative = rec(i+1, sum - nums[i], n, total, target, nums, dp);
        return dp[i][total+sum] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(total*2+1, -1));
        return rec(0, 0, n, total, target, nums, dp);
    }
};