class Solution {
public:
    bool isValid(string S) {
        int i,n;
        n = S.length();
        
        stack<char> st;
        
        for(i=0 ; i<n ; i++){
            char ch = S[i];
            
            if(ch == '(' || ch == '{' || ch == '['){
                // Open Parenthesis
                st.push(ch);
            }
            else{
                // Closed Parenthesis
                if(st.empty()){ 
                    return false;  // Special Case
                }
                
                if(ch == ')'){   
                    if(st.top() == '('){
                        st.pop();
                    }          
                    else{
                        return false;
                    }
                }
                else if(ch == '}'){
                    if(st.top() == '{'){
                        st.pop();
                    }          
                    else{
                        return false;
                    }                    
                }
                else{
                    if(st.top() == '['){
                        st.pop();
                    }          
                    else{
                        return false;
                    }                    
                }
            }
        }
        
        return (st.empty())? true : false;
    } 
};