class SubrectangleQueries {
public:
    int m,n;
    vector<vector<int>> rectangle;
    
    // Constructor
    SubrectangleQueries(vector<vector<int>> &V) {
        m = V.size();
        n = V[0].size();
        
        for(int i=0 ; i<m ; i++){
            rectangle.push_back(V[i]);
        }
    }
    
    // Functions
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        int i,j;
        
        for(i=row1 ; i<=row2 ; i++){
            for(j=col1 ; j<=col2 ; j++){
                rectangle[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */