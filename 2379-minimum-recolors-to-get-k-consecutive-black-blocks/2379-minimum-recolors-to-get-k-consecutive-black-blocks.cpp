#define inf 1000000000

class Solution {
public:
    int minimumRecolors(string S, int k) {
        int i,j,n,currentCnt,minCnt;
        n = S.length();
        
        minCnt = inf;
        for(i=0 ; i<=(n-k) ; i++){
            currentCnt = 0;
            for(j=i ; j<=(i+k-1) ; j++){
                if(S[j] == 'W'){
                    currentCnt++;
                }
            }
            
            minCnt = min(minCnt,currentCnt);
        }
        
        return minCnt;
    }
};