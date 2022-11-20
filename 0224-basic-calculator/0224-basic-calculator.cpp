class Solution {
public:
    int calculate(string str){
        long long i,n,digit,ans;
                        
        // 1: Getting rid of blank spacec:  str --> S
        string S;
        for(i=0 ; i<str.length() ; i++){
            if(str[i] != ' '){
                S += str[i];
            }            
        }                    
        n = S.length();
                
        
        // 2: Getting rid of brackets:  S --> expression
        stack<char> st; 
        bool signFlip = false;
        string expression;   // Expression without brackets                
        
        for(i=0 ; i<n ; ){                                    
            if(i<=(n-2) && S[i] == '-' && S[i+1] == '('){
                // -(
                st.push('-');
                signFlip = !signFlip;
                i += 2;
            }
            else if(i<=(n-2) && S[i] == '+' && S[i+1] == '('){
                // +(
                st.push('+');
                i += 2;
            }
            else if(S[i] == '('){
                // (
                st.push('+');
                i += 1;                
            }            
            else{
                if(S[i] == ')'){
                    // )
                    if(st.top() == '+'){
                        st.pop();
                        i++;
                    }
                    else{
                        signFlip = !signFlip;
                        st.pop();
                        i++;
                    }                        
                }
                else{
                    if(i<= (n-2) && S[i] == '+' && (S[i+1] >= '0' && S[i+1] <= '9') ){
                        // +a form
                        if(signFlip){
                            expression += '-';                            
                            i++;
                            
                            while(i<n && (S[i] >= '0' && S[i] <= '9')){
                                expression += S[i];    
                                i++;
                            }                                                        
                        }
                        else{
                            expression += '+';
                            i++;
                            
                            while(i<n && (S[i] >= '0' && S[i] <= '9')){
                                expression += S[i];    
                                i++;
                            }                            
                        }                                 
                    }
                    else if(i<n && (S[i] >= '0' && S[i] <= '9')){
                        // a form
                        if(signFlip){
                            expression += '-';
                            while(i<n && (S[i] >= '0' && S[i] <= '9')){
                                expression += S[i];    
                                i++;
                            }                            
                        }
                        else{
                            expression += '+';
                            while(i<n && (S[i] >= '0' && S[i] <= '9')){
                                expression += S[i];    
                                i++;
                            }                            
                        }
                    }
                    else if(i<= (n-2) && S[i] == '-' && (S[i+1] >= '0' && S[i+1] <= '9') ){
                        // -a form
                        if(signFlip){
                            expression += '+';
                            i++;
                            while(i<n && (S[i] >= '0' && S[i] <= '9')){
                                expression += S[i];    
                                i++;
                            }                            
                            
                        }
                        else{
                            expression += '-';
                            i++;

                            while(i<n && (S[i] >= '0' && S[i] <= '9')){
                                expression += S[i];    
                                i++;
                            }                                                        
                        }
                    }                                        
                }
            }                        
        }
                                                
        // 3
        // cout<<expression<<"\n";
        n = expression.length();
        
        ans = 0;
        for(i=0 ; i<n ; ){                                   
            if(i<=(n-2) && expression[i] == '+'){
                // +a
                i++;
                
                string currentValue;
                while(i<n && (expression[i] >= '0' && expression[i] <= '9')){
                    currentValue += expression[i];
                    i++;
                }                                
                ans += stoi(currentValue);
            }   
            else if(i<=(n-2) && expression[i] == '-'){
                // -a
                i++;
                
                string currentValue;
                while(i<n && (expression[i] >= '0' && expression[i] <= '9')){
                    currentValue += expression[i];
                    i++;
                }                                
                ans -= stoi(currentValue);                
            }
            else{
                // a
                string currentValue;
                while(i<n && (expression[i] >= '0' && expression[i] <= '9')){
                    currentValue += expression[i];
                    i++;
                }                
                ans += stoi(currentValue);                 
            }
        }
        
        return ans;
    }
};