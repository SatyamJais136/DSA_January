class Solution {
public:
    int rec(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for(int k = i+1; k < j; k++){
            int op = rec(i, k, nums, dp) + rec(k, j, nums, dp) + (nums[i] * nums[j] * nums[k]);
            ans = max(ans, op);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int m = nums.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return rec(0, m-1, nums, dp);
    }
};