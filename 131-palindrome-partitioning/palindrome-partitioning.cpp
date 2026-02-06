class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void rec(int idx, string s, vector<string> &path, vector<vector<string>> &ans){
        if(idx == s.size()){  // base case
            ans.push_back(path);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(idx, i, s)){
                path.push_back(s.substr(idx, i-idx+1));
                rec(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        rec(0, s, path, ans);
        return ans;
    }
};