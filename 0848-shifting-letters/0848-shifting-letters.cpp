class Solution {
public:
    string shiftingLetters(string S, vector<int>& shift) {
        long long n,i,currentValue;
        n = S.length();
        
        // 1
        for(i=(n-2) ; i>=0 ; i--){
            shift[i] = (shift[i]%26 + shift[i+1]%26)%26;
        }
        
        // 2
        string solution;
        for(i=0 ; i<n ; i++){
            currentValue = (S[i] - 'a');
            currentValue += shift[i];
            currentValue %= 26;
            
            solution += (char)(currentValue + (int)('a'));                            
        }
        
        return solution;
    }
};