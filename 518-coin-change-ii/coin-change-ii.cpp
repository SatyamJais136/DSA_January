class Solution {
public:
    int rec(int i, int currSum, int amount, vector<int> &coins, vector<vector<int>> &dp){
        int n = coins.size();
        if(currSum == amount) return 1;
        if(n == i || currSum > amount) return 0;
        if(dp[i][currSum] != -1) return dp[i][currSum];
        int take = rec(i, currSum+coins[i], amount, coins, dp);
        int notTake = rec(i+1, currSum, amount, coins, dp);
        return dp[i][currSum] = (take+notTake);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return rec(0, 0, amount, coins, dp);
    }
};