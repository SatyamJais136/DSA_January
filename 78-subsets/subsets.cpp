class Solution {
public:
    void helper(int idx, vector<int> &nums, vector<int> &cur, vector<vector<int>> &res){
        res.push_back(cur);
        for(int i = idx; i < nums.size(); i++){
            cur.push_back(nums[i]);
            helper(i+1, nums, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(0, nums, cur, res);
        return res;
    }
};