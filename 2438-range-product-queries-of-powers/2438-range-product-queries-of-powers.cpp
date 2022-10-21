#define mod 1000000007

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        long long digit,s,e,i,j,ans;
        
        // Step 1: Generate power[]                 
        vector<long long> power;
        int x = 1;
        while(n > 0){            
            if(n%2){
                power.push_back(x);
            }
            n /= 2;
            x *= 2;
        }

        // Step 2: Determine solution        
        vector<int> solution;
        for(i=0 ; i<queries.size() ; i++){
            s = queries[i][0];
            e = queries[i][1];  
            
            ans = 1;
            for(j=s ; j<=e ; j++){
                ans = (ans%mod * power[j]%mod)%mod;
            }            
            solution.push_back(ans);                                                
        }
        
        return solution;        
    }
};