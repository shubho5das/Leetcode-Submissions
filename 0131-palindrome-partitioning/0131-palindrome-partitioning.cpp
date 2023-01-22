class Solution {
public:
    
    static bool isPalindrome(string S){
        int i,j,n;
        n = S.length();
        
        i = 0, j = (n-1);
        while(i < j){
            if(S[i] != S[j]){
                return false;
            }
            
            i++, j--;
        }
        
        return true;
    }
    
    void findPartitions(string &S,int n,int i,vector<string> &current,vector<vector<string>> &solution){
        int j;
        
        // Base Case
        if(i == n){
            solution.push_back(current);
            return;
        }
        
        // General Case
        for(j=i ; j<n ; j++){
            if(isPalindrome(S.substr(i,(j-i+1)))){
                current.push_back(S.substr(i,(j - i + 1)));
                findPartitions(S,n,j+1,current,solution);
                current.pop_back(); // backtrack                
            }
        }
    }
    
    vector<vector<string>> partition(string S) {
        int n,i;
        n = S.length();
                
        vector<vector<string>> solution;
        vector<string> current;
        findPartitions(S,n,0,current,solution);
                
        return solution;
    }
};