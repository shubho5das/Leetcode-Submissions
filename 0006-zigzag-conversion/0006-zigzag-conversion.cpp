class Solution {
public:
    string convert(string S, int numRows) {
        int i,j,n;
        n = S.length();
        
        // 1
        unordered_map<int,vector<char>> M; // {idx,corresponding chars}
        
        i = 0;
        while(i<n){
            // Down
            for(j=0 ; i<n && j<numRows ; j++,i++){
                M[j].push_back(S[i]);
            }
            
            // Up
            for(j=(numRows - 2) ; i<n && j>=1 ; j--,i++){
                M[j].push_back(S[i]);
            }
        }
        
        
        // 2
        string solution;
        for(i=0 ; i<numRows ; i++){
            for(j=0 ; j<M[i].size() ; j++){
                solution += M[i][j];
            }     
        }
        
        return solution;        
    }
};