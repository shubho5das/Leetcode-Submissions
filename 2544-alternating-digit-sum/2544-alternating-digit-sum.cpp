class Solution {
public:
    int alternateDigitSum(int n) {
        int i,digit,ans;
        
        string str = to_string(n);
        ans = 0;
        for(i=0 ; i<str.length() ; i++){
            digit = (int)(str[i] - '0');
            if(i%2 == 0){
                ans += digit;
            }
            else{
                ans -= digit;
            }
        }
        
        return ans;
    }
};