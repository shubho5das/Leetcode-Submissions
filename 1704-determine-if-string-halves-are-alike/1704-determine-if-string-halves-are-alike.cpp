class Solution {
public:
    bool isVowel(char c){
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        return (vowels.find(c) != vowels.end())? true : false;
    }
    
    bool halvesAreAlike(string S) {
        int n,i,cntVowelLeft,cntVowelRight;
        n = S.length();
        
        cntVowelLeft = 0;        
        for(i=0 ; i<n/2 ; i++){
            if(isVowel(S[i])){
                cntVowelLeft++;
            }
        }
        
        cntVowelRight = 0;
        for(i=n/2 ; i<n ; i++){
            if(isVowel(S[i])){
                cntVowelRight++;
            }
        }
        
        return (cntVowelLeft == cntVowelRight);
    }
};