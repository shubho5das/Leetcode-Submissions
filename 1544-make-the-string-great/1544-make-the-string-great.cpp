class Solution {
public:
    
    bool isGood(string S){
        int n,i,diff;
        n = S.length();
        
        for(i=0 ; i<=(n-2) ; i++){
            diff = (S[i+1] - S[i]);
            if(diff == 32 || diff == -32){
                return false;
            }
        }
        
        return true;
    }
    
    string makeGood(string S) {
        int i,n;
        
        while(!isGood(S)){                        
            n = S.length();
            
            string modifiedString;
            for(i=0 ; i<n ; ){
                if( (i <= (n-2)) && ((S[i+1] - S[i] == 32) || (S[i+1] - S[i] == -32)) ){
                    i += 2;
                }
                else{
                    modifiedString += S[i];
                    i += 1;
                }
            }
            
            S = modifiedString;            
        }
        
        return S;                
    }
};