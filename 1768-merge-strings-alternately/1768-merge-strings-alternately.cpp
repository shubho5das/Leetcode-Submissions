class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,n1,n2;
        n1 = word1.length(), n2 = word2.length();
        
        string solution;
        
        i = 0;
        while(i<n1 && i<n2){
            solution += word1[i];
            solution += word2[i];
            i++;
        }
        
        if(i < n1){
            solution += word1.substr(i,(n1-i));
        }
        else if(i < n2){
            solution += word2.substr(i,(n2-i));
        }
        
        return solution;
    }
};