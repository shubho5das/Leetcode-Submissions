class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n,m,i,j,cnt;
        n = strs.size();
        m = strs[0].length();
        
        cnt = 0;
        for(j=0 ; j<m ; j++){
            bool isSorted = true;
            for(i=1 ; i<n ; i++){
                if(!(strs[i][j] >= strs[i-1][j])){
                    isSorted = false;
                    break;
                }                    
            }
                        
            if(!isSorted){
                cnt++;
            }
        }
        
        return cnt;        
    }
};