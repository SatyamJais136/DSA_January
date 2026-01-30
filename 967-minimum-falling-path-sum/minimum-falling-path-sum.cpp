class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int mn = matrix[i-1][j];
                if((j-1) >= 0) mn = min(mn, matrix[i-1][j-1]);
                if((j+1) < n) mn = min(mn, matrix[i-1][j+1]);
                matrix[i][j] += mn;
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, matrix[n-1][i]);
        }
        return ans;
    }
};