class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxi = INT_MIN;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                count = 1;
                ans = 1;
            }
            else if(nums[i] == maxi){
                count++;
                ans = max(ans, count);
            }
            else count = 0;
        }
        return ans;
    }
};