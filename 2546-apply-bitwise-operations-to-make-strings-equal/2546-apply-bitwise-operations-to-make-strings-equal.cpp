class Solution {
public:
    bool makeStringsEqual(string S, string T) {
        int n,i;
        n = S.length();
        
        // 1
        bool moveAllowed = false, onePresentinS = false, onePresentinT = false;
        for(i=0 ; i<n ; i++){
            if(S[i] == '1'){
                onePresentinS = true;
            }
            if(T[i] == '1'){
                onePresentinT = true;
            }
        } 
        if(onePresentinS && onePresentinT){
            moveAllowed = true;
        }
        
        // 2
        for(i=0 ; i<n ; i++){
            if(S[i] != T[i] && !moveAllowed){
                return false;
            }
        }
        
        return true;                
    }
};