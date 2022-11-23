class Solution {
public:
    bool isValidRow(vector<vector<char>>& board,int i){
        int j;
        
        bool visited[10] = {false}; 
        for(j=0 ; j<9 ; j++){
            if(board[i][j] == '.'){
                continue;
            }
            
            if(visited[board[i][j] - '0']){
                return false;
            }
            visited[board[i][j] - '0'] = true;
        }
        
        return true;        
    }
    
    bool isValidColumn(vector<vector<char>>& board,int j){
        int i;
        
        bool visited[10] = {false}; 
        for(i=0 ; i<9 ; i++){
            if(board[i][j] == '.'){
                continue;
            }
            
            if(visited[board[i][j] - '0']){
                return false;
            }
            visited[board[i][j] - '0'] = true;
        }
        
        return true;                
    }
    
    bool isValidSubgrid(vector<vector<char>>& board,int row,int col){
        int i,j;
        
        bool visited[10] = {false};             
        for(i=row ; i<(row+3) ; i++){
            for(j=col ; j<(col+3) ; j++){
                if(board[i][j] == '.'){
                    continue;
                }                
                
                if(visited[board[i][j] - '0']){
                    return false;
                }
                visited[board[i][j] - '0'] = true;
            }
        }
        
        return true;
    }
                
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j,n;
        n = 9;
        
        // Checking rows
        for(i=0 ; i<n ; i++){
            if(!isValidRow(board,i)){
                return false;
            }
        }
        
        // Checking columns
        for(j=0 ; j<n ; j++){
            if(!isValidColumn(board,j)){
                return false;
            }
        }
        
        // Checking subgrids
        for(i=0 ; i<n ; i+=3){
            for(j=0 ; j<n ; j+=3){
                if(!isValidSubgrid(board,i,j)){
                    return false;
                }
            }
        }
        
        return true;        
    }
};