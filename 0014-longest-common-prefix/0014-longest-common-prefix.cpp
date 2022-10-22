#define inf 1000000000

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n,i,j,currentLen,smallestLen;
        n = strs.size();
        
        smallestLen = inf;
        for(i=0 ; i<n ; i++){
            currentLen = strs[i].length();
            smallestLen = min(smallestLen,currentLen);
        }
        
        string solution = "";
        for(i=1 ; i<=smallestLen ; i++){
            string currentPrefix = strs[0].substr(0,i);
            
            bool isValid = true;
            for(j=0 ; j<n ; j++){
                if(currentPrefix != strs[j].substr(0,i)){
                    isValid = false;
                }
            }
            
            if(isValid){
                solution = currentPrefix;
            }
        }
        
        return solution;
    }
};