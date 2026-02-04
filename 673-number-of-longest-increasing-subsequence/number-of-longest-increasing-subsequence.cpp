class Solution {
public:
    pair<int,int> rec(int i, int prev, int n, vector<int> &nums, vector<vector<pair<int,int>>> &dp){
        if(i == n) return {0,1}; 
        if(dp[i][prev+1] != make_pair(-1,-1)) return dp[i][prev+1];
        auto notTake = rec(i+1, prev, n, nums, dp);
        pair<int,int> best = notTake;
        if(prev == -1 || nums[i] > nums[prev]){
            auto take = rec(i+1, i, n, nums, dp);
            take.first += 1; // include nums[i]

            if(take.first > best.first){
                best = take;
            } else if(take.first == best.first){
                best.second += take.second; // add counts
            }
        }

        return dp[i][prev+1] = best;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1, {-1,-1}));
        auto ans = rec(0, -1, n, nums, dp);
        return ans.second; // number of LIS
    }
};