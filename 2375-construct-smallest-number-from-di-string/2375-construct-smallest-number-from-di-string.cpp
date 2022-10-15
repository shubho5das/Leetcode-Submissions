class Solution {
public:
    string smallestNumber(string pattern) {
        int n,i;
        n = pattern.size();
        
        string current;
        char c = '1';
        for(i=0 ; i<(n+1) ; i++){
            current += c;
            c++;
        }
        
        string solution;
        do{
            // Checking if the currentString is valid or not
            bool isValid = true;
            for(i=0 ; i<n ; i++){
                if(pattern[i] == 'I' && current[i+1] < current[i]){
                    isValid = false;
                    break;
                }
                else if(pattern[i] == 'D' && current[i+1] > current[i]){
                    isValid = false;
                    break;
                }
            }
            
            if(isValid){
                solution = current;
                break;
            }
        }
        while(next_permutation(current.begin(),current.end()));
        
        return solution;
    }
};