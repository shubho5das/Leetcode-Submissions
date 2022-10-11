class Solution {
public:
    string removeStars(string S) {
        int n,i,cnt;
        n = S.length();
        
        // 1
        vector<bool> toErase(n,false);
        cnt = 0;
        for(i=(n-1) ; i>=0 ; i--){
            if(S[i] == '*'){
                cnt++;
            }
            else if(cnt >= 1){
                toErase[i] = true;
                cnt--;
            }
        }
        
        // 2
        string solution;
        for(i=0 ; i<n ; i++){
            if(!((toErase[i]) || (S[i] == '*'))){
                solution += S[i];
            }
        }
        
        return solution;
    }
};