class Solution {
public:    
    bool checkPrime(int n){
        int i;

        if(n==1 || n==0)
            return false;

        for(i=2 ; i*i <= n ; i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }    
    
    int distinctPrimeFactors(vector<int>& nums) {
        int n,i,j,val,cnt;
        n = nums.size();
        
        bool isPrime[1007] = {false};
        
        isPrime[0] = false;
        isPrime[1] = false;
        isPrime[2] = true;
        for(i=0 ; i<=1000 ; i++){
            if(checkPrime(i)){
                isPrime[i] = true;
            }
            else{
                isPrime[i] = false;
            }
        }
        
        vector<bool> visited(1007,false);                
        for(i=0 ; i<n ; i++){                        
            for(j=2 ; j<=nums[i] ; j++){
                if(nums[i]%j == 0 && isPrime[j]){
                    visited[j] = true;
                }
            }            
        }
        
        cnt = 0;
        for(i=0 ; i<=1002 ; i++){
            if(visited[i]){
                cnt++;
            }
        }        
        
        return cnt;
    }
};