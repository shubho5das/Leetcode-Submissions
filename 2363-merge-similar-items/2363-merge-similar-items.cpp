class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int i,j,n1,n2;
        n1 = items1.size(), n2 = items2.size();
        
        map<int,int> M; // {val,wt}
        for(i=0 ; i<n1 ; i++){
            M[items1[i][0]] += items1[i][1];
        }
        for(i=0 ; i<n2 ; i++){
            M[items2[i][0]] += items2[i][1];
        }
        
        vector<vector<int>> solution;
        for(auto x : M){
            solution.push_back({x.first,x.second});
        }
        
        return solution;                                
    }
};