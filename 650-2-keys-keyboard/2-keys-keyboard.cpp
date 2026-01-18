class Solution {
public:
    bool isPrime(int n){
        if(n == 0 || n == 1) return false;
        for(int i = 2; i*i  <= n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }

    int gd(int n){
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0) return (n/i); 
        }
        return 1;
    }

    int minSteps(int n) {
        int  cnt = 0;
        while(n > 1){
            if(isPrime(n)){
                cnt += n;
                break;
            }
            int hf = gd(n);
            cnt += (n/hf);
            n = hf;
        }
        return cnt;
    }
};