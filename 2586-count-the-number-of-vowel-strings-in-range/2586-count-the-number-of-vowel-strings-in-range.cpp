class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int i,len,cnt;
        
        cnt = 0;
        for(i=left ; i<=right ; i++){
            string currentWord = words[i];
            len = currentWord.length();
            
            if(isVowel(currentWord[0]) && isVowel(currentWord[len-1])){
                cnt++;
            }
        }
        
        return cnt;
    }
};