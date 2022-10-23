class Solution {
public:
    int gcd(int a, int b){ 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  
    }     
    
    int subarrayGCD(vector<int>& nums, int k) {
        int i,j,n,cnt,g;
        n = nums.size();
        
        cnt = 0;
        for(i=0 ; i<n ; i++){
            g = 0;
            for(j=i ; j<n ; j++){
                g = gcd(g,nums[j]);
                
                if(g == k){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};