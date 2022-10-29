class Solution {
public:
    int lengthOfLastWord(string S) {
        int len,i,n,s,e;
        n = S.length();
        
        len = 0;
        e = (n-1);
        while(e >= 0 && S[e] == ' '){
            e--;
        }
        
        s = (e-1);
        while(s >= 0 && S[s] != ' '){
            s--;
        }
        
        int ans = (e-s);
        return ans;                        
    }
};