class Solution {
public:
    string orderlyQueue(string S, int k) {
        int i,n;
        n = S.length();
        
        if(k == 1){
            string minString = S;
            for(i=0 ; i<n ; i++){
                string currentString;
                currentString += S.substr(i+1,(n-i-1));
                currentString += S.substr(0,(i+1));
                                
                minString = min(minString,currentString);
            }
            
            return minString;
        }
        else{
            sort(S.begin(),S.end());
            return S;                
        }
    }
};