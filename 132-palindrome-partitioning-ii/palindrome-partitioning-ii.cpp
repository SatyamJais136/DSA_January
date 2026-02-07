class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    int rec(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j || isPalindrome(i, j, s)) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            if(isPalindrome(i, k, s)){
                int op = 1 + rec(k+1, j, s, dp);
                ans = min(ans, op);
            }
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, n-1, s, dp);
    }
};