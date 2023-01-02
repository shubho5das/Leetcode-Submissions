class Solution {
public:
    int minimumPartition(string S, int k) {
        long long n,i,currentValue,cnt;
        n = S.length();
        
        cnt = 0;
        for(i=0 ; i<n ; ){            
            currentValue = (int)(S[i] - '0');
                
            while((i+1) < n && (10*currentValue + (long long)(S[i+1] - '0')) <= k){
                i++;
                currentValue = (10*currentValue + (long long)(S[i] - '0'));                
            }
            
            if(currentValue <= k){
                cnt++;
            }
            else{
                return -1;
            }
            
            i++;                                    
        }       
        
        return cnt;
    }
};