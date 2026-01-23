class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &v, int k, int n, int sum, int idx){
        if(k == 0 && sum == n){
            ans.push_back(v);
        }
        if(sum > n || k < 0) return;
        for(int i = idx; i <= 9; i++){
            v.push_back(i);
            combination(ans, v, k-1, n, sum+i, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;;
        combination(ans, v, k, n, 0, 1);
        return ans;
    }
};