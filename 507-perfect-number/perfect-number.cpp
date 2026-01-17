class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0 || num == 1) return false;
        int cnt = 0;
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                cnt += i;
            }
        }
        cnt = cnt + 1;
        if(cnt == num) return true;
        else return false;
    }
};