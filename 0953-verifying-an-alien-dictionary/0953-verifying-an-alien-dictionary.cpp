class Solution {
public:
    bool isOkay(string &word1,string &word2,unordered_map<char,int> &position){
        // Is word1 <= word2?
        int n,i;
        n = min(word1.length(),word2.length());
        
        i = 0;
        while(i < n && word1[i] == word2[i]){
            i++;
        }
        
        if(i == n){
            return (word1.length() <= word2.length()); 
        }
        else{
            return (position[word1[i]] < position[word2[i]]);
        }
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int i,n;
        n = words.size();
        
        unordered_map<char,int> position; // {char,pos}
        for(i=0 ; i<26 ; i++){
            position[order[i]] = i;
        }
        
        for(i=0 ; i<=(n-2) ; i++){
            if(!isOkay(words[i],words[i+1],position)){
                return false;
            }    
        }
        
        return true;                        
    }
};