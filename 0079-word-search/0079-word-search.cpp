class Solution {
public:    
    void checkWordPresent(vector<vector<char>> &board,int m,int n,string &word,int row,int col,int idx,vector<vector<bool>> &visited,bool &isPresent){
        // Base Case
        if(idx == word.size()){
            isPresent = true;
            return;
        }
        
        // General Case
        if((row >= 0 && row <= (m-1)) && (col >= 0 && col <= (n-1)) && !visited[row][col] && board[row][col] == word[idx]){
            visited[row][col] = true;
            
            checkWordPresent(board,m,n,word,row+1,col,idx+1,visited,isPresent);
            checkWordPresent(board,m,n,word,row-1,col,idx+1,visited,isPresent);
            checkWordPresent(board,m,n,word,row,col+1,idx+1,visited,isPresent);
            checkWordPresent(board,m,n,word,row,col-1,idx+1,visited,isPresent);
            
            visited[row][col] = false; // Backtracking
        }        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int i,j,m,n;
        m = board.size(), n = board[0].size();
        
        for(i=0 ; i<m ; i++){
            for(j=0 ; j<n ; j++){
                bool isPresent = false;                
                vector<vector<bool>> visited(m,vector<bool>(n,false));
                
                checkWordPresent(board,m,n,word,i,j,0,visited,isPresent);
                
                if(isPresent){
                    return true;
                }
            }
        }        
        
        return false;
    }
};