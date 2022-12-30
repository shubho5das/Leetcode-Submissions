class Solution {
public:
    void dfs(int src,int target,vector<bool> &visited, vector<int> &current, vector<vector<int>> &solution, vector<vector<int>>& adjList){
        // Base Case
        if(src == target){
            current.push_back(target);
            solution.push_back(current);
            current.pop_back();
            return;
        }
                
        visited[src] = true;
        current.push_back(src);
        
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,target,visited,current,solution,adjList);
            }
        }
        
        visited[src] = false;
        current.pop_back(); // Backtracking                
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adjList) {
        int n,i;
        n = adjList.size();
        
        vector<bool> visited(n+1,false);
        
        vector<vector<int>> solution;
        vector<int> current;
        dfs(0,(n-1),visited,current,solution,adjList);
        
        return solution;
    }
};