class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++){
            int u = boxTypes[i][1]; // units per box
            v.push_back({u, i});
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int ans = 0;
        for(int i = 0; i < n; i++){
            int idx = v[i].second;
            int boxes = min(truckSize, boxTypes[idx][0]);
            ans += boxes * boxTypes[idx][1];
            truckSize -= boxes;
            if(truckSize == 0) break;
        }
        return ans;
    }
};