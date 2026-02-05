class Solution {
public:
    int rec(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(i == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int notTake = rec(i-1, amount, coins, dp);
        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1 + rec(i, amount - coins[i], coins, dp);
        }
        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans =  rec(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};