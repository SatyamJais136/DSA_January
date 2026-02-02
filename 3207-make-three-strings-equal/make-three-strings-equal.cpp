class Solution {
public:
    int lcp(string &s1, string &s2, string &s3){
        int n = min({s1.size(), s2.size(), s3.size()});
        int l = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i] && s2[i] == s3[i]) l++;
            else break;
        }
        return l;
    }

    int findMinimumOperations(string s1, string s2, string s3) {
        int l = lcp(s1, s2, s3);
        if(l == 0) return -1;
        return ((s1.size() - l) + (s2.size() - l) + (s3.size() - l));
    }
};