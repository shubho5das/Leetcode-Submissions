class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long n,i,digit,prevValue,currentValue;
        n = word.length();
        
        vector<int> solution(n);
        
        prevValue = 0;
        for(i=0 ; i<n ; i++){
            digit = int(word[i] - '0');
            currentValue = ((prevValue%m * 10)%m + digit%m) % m; 
            
            solution[i] = (currentValue == 0)? 1 : 0; 
            prevValue = currentValue;
        }
        
        return solution;
    }
};