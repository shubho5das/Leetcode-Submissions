class Solution {
public:
    string reverseWords(string S){
        int n,i;
        n = S.length();
        
        // 1
        stack<string> st;
        for(i=0 ; i<n ; ){
            if(S[i] == ' '){
                i++;
            }
            else{
                string currentWord;
                while(i<n && S[i] != ' '){
                    currentWord += S[i];
                    i++;
                }
                
                st.push(currentWord);
            }
        }
                        
        // 2            
        string solution;
        while(st.size() >= 1){
            solution += st.top();
            st.pop();
            
            if(st.size() >= 1){
                solution += " ";
            }
        }
        
        return solution;
    }
};