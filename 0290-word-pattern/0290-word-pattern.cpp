class Solution {
public:
    bool wordPattern(string pattern, string S) {
        int n,i,j;
        n = pattern.length();
        
        vector<string> words;
        for(i=0 ; i<S.length() ; ){
            j = i;
            string current;
            while(j<S.length() && S[j] != ' '){
                current += S[j];
                j++;
            }
            words.push_back(current);
            i = (j+1);
        }        
        
        if(words.size() != n){
            return false;
        }        
        
        // Checking char --> word mapping
        unordered_map<char,string> M1; // {char,word}
        for(i=0 ; i<n ; i++){
            if(M1.find(pattern[i]) != M1.end()){
                if(M1[pattern[i]] != words[i]){
                    return false;
                }                
            }
            else{
                M1[pattern[i]] = words[i];
            }
        }
        
        // Checking word --> char mapping
        unordered_map<string,char> M2; // {word,char}
        for(i=0 ; i<n ; i++){
            if(M2.find(words[i]) != M2.end()){
                if(M2[words[i]] != pattern[i]){
                    return false;
                }                
            }
            else{
                M2[words[i]] = pattern[i];
            }
        }
                
        return true;
    }
};