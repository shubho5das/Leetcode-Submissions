class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i;
        
        vector<int> prev,current;
          
        current = {1}; // i = 0
        for(i=1 ; i<=rowIndex ; i++){
            prev = current;
            
            current.clear();
            current.push_back(prev.front());
            for(i=1 ; i<prev.size() ; i++){
                current.push_back(prev[i] + prev[i-1]);
            }            
            current.push_back(prev.back());                        
        }
        
        return current;        
    }
};