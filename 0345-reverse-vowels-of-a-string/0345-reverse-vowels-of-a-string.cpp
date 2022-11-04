class Solution {
public:
    bool isVowel(char c){
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        if(vowels.find(c) != vowels.end()){
            return true;
        }
        else{
            return false;
        }
    }
    
    string reverseVowels(string S){
        int n,i;
        n = S.length();
        
        vector<char> vowel;
        vector<int> vowelPosition;
        for(i=0 ; i<n ; i++){
            if(isVowel(S[i])){
                vowel.push_back(S[i]);
                vowelPosition.push_back(i);
            }
        }
        
        reverse(vowel.begin(),vowel.end());
        
        for(i=0 ; i<vowelPosition.size() ; i++){
            S[vowelPosition[i]] = vowel[i];
        }
        
        return S;     
    }
};