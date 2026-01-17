class Solution {
public:
    bool isPrime(int n){
        if(n == 1 || n == 0) return false;
        int limit = (int)sqrt(n);
        for(int i = 2; i <= limit; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int smallestValue(int n) {
        if(n == 4) return 4;
        if(isPrime(n)) return n; // base case
        int sum = 0;
        int temp = n;
        for(int i = 2; i * i <= temp; i++){
            while(temp % i == 0){
                sum += i;
                temp /= i;
            }
        }
        if(temp > 1) sum += temp;
        return smallestValue(sum);
    }
};