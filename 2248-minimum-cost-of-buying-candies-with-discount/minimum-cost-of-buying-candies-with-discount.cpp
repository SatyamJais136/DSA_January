class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int minc = 0;
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        for(int i = 0; i < n; i++){
            if(i % 3 != 2) minc += cost[i];
        }
        return minc;
    }
};