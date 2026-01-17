class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0 || num == 1) return false;
        int cnt = 0;
        for(int i = 2; i < sqrt(num); i++){
            if(num % i == 0){
                int f = num/i;
                cnt = cnt + f + i;
            }
        }
        cnt = cnt + 1;
        return (cnt == num);
    }
};