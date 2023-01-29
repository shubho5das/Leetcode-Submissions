#define mod 1000000007

class Solution {
public:
    long long integer_power(long long x, long long y){
        long long res = 1;  
        x = x % mod;                 
        if (x == 0) 
            return 0;

        while (y > 0){    
            if (y & 1){
                res = (res*x) % mod;  
            }  
                            
            y = y>>1;  
            x = (x*x) % mod;  
        }  
        return res;  
    }    
    
    int monkeyMove(long long n) {        
        long long ans;
                
        ans = integer_power(2,n);
        ans = (ans - 2 + mod) % mod;
                
        return ans;        
    }
};