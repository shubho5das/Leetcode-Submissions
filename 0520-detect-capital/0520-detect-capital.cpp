class Solution {
public:
    bool detectCapitalUse(string S) {
        int n,i;
        n = S.length();
        
        // 1 and 2
        bool allCapital = true, allSmall = true;
        for(i=0 ; i<n ; i++){
            if(S[i] >= 'a' && S[i] <= 'z'){
                allCapital = false;
            }    
            if(S[i] >= 'A' && S[i] <= 'Z'){
                allSmall = false;
            }
        }
        
        // 3
        bool onlyFirstLetterCapital = true;
        if(S[i] >= 'a' && S[i] <= 'z'){
            onlyFirstLetterCapital = false;
        }
        for(i=1 ; i<n ; i++){
            if(S[i] >= 'A' && S[i] <= 'Z'){
                onlyFirstLetterCapital = false;
            }
        }
        
        return (allSmall || allCapital || onlyFirstLetterCapital);                
    }
};