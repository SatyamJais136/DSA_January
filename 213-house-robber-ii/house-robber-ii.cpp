class Solution {
public:
    int robLinear(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        // case1: exclude first house
        vector<int> case1(nums.begin()+1, nums.end());
        // case2: exclude last house
        vector<int> case2(nums.begin(), nums.end()-1);
        return max(robLinear(case1), robLinear(case2));
    }
};