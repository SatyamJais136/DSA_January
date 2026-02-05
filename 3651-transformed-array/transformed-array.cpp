class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) ans[i] = 0;
            else{
                int newIdx = (i + nums[i]) % n;
                if(newIdx < 0) newIdx += n;
                ans[i] = nums[newIdx];
            }
        }
        return ans;
    }
};