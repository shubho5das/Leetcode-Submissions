class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int i,n1,n2;
        n1 = word1.size();
        n2 = word2.size();
        
        bool visited[26] = {false};
        
        int freq1[26] = {0};
        for(i=0 ; i<n1 ; i++){
            freq1[word1[i] - 'a']++;
            visited[word1[i] - 'a'] = true;
        }
        
        int freq2[26] = {0};
        for(i=0 ; i<n2 ; i++){
            freq2[word2[i] - 'a']++;
            visited[word2[i] - 'a'] = true;
        }     
                        
        // 1
        bool sameCharacters = true;
        for(i=0 ; i<26 ; i++){
            if(visited[i]){
                if(!(freq1[i] >= 1 && freq2[i] >= 1)){
                    sameCharacters = false;
                }
            }
        }
                
                
        // 2            
        bool sameRatio = true;
        
        sort(freq1,freq1+26);
        sort(freq2,freq2+26);
            
        for(i=0 ; i<26 ; i++){
            if(freq1[i] != freq2[i]){
                sameRatio = false;
                break;
            }                
        }            
            
        return (sameCharacters && sameRatio)? true : false;
    }
};