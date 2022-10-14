class Solution {
public:
    int secondsToRemoveOccurrences(string S){
        int i,n,t;
        n = S.length();
        
        t = 0;
        while(1){
            bool found = false;
            for(i=0 ; i<=(n-2) ; ){
                if(S[i] == '0' && S[i+1] == '1'){
                    S[i] = '1', S[i+1] = '0';
                    found = true;
                    i += 2;
                }
                else{
                    i++;
                }
            }
            
            if(found){
                t++;
            }       
            else{
                break;
            }
        }
        
        return t;        
    }
};