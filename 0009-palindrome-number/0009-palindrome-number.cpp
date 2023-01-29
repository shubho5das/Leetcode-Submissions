class Solution {
public:    
    bool isPalindrome(long long x) {
        long long i,j,n;
        
        string str = to_string(x);
        n = str.length();
        
        i = 0, j = (n-1);
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            
            i++, j--;
        }
        
        return true;               
    }
};