class Solution {
public:
    bool isPalindrome(string S){
        int n,i,j;
        n = S.length();
        
        i = 0, j = (n-1);
        while(i < j){
            if(S[i] != S[j]){
                return false;
            }
            i++, j--;
        }
        
        return true;
    }
    
    string convertToBaseb(int n,int b){
        int digit;
        
        string solution;        
        while(n > 0){
            digit = n%b;
            solution +=  (char)(digit + (int)('0'));
            n /= b;            
        }
        
        reverse(solution.begin(),solution.end());
        return solution;
    }
    
    bool isStrictlyPalindromic(int n) {
        int b;
        
        for(b=2 ; b<=(n-2) ; b++){
            string str = convertToBaseb(n,b);
            if(!isPalindrome(str)){
                return false;
            }
        }
        
        return true;
    }
};