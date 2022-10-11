class Solution {
public:
    
    /****************** TOPO SORT ********************/
    void topoSort(int src,vector<bool> &visited,deque<int> &ordering,vector<vector<int>> &adjList){
        visited[src] = true;
        
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                topoSort(nbr,visited,ordering,adjList);
            }
        }
        
        ordering.push_front(src); // Bottom-up
    }    
    
    /****************** IS CYCLIC? ********************/
    void dfs(int src,vector<bool> &visited,vector<bool> &tempVisited,vector<vector<int>> &adjList,vector<bool> &currentPath,bool &cyclePresent){
        visited[src] = true;
        
        tempVisited[src] = true;
        currentPath[src] = true;
        
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,visited,tempVisited,adjList,currentPath,cyclePresent);
            }
            else if(visited[nbr] && currentPath[nbr]){
                cyclePresent = true;
                return;
            }
        }
        
        tempVisited[src] = false;  // backtracking
        currentPath[src] = false; 
    }    
    
    bool isCyclic(int n, vector<vector<int>> &adjList) {
        int i;

        vector<bool> visited(n+5,false);     // Original Visited[]] - common for all the CC's
        vector<bool> tempVisited(n+5,false); // Temporaary Visited[] 
        vector<bool> currentPath(n+5,false);

        bool cyclePresent = false;
        for(i=0 ; i<n ; i++){
            if(!visited[i]){
                dfs(i,visited,tempVisited,adjList,currentPath,cyclePresent);
                if(cyclePresent){
                    break;
                }
            }
        }

        return (cyclePresent)? true : false;
    }    
    
                
    /****************** MAIN FUNCTION ********************/
    void findOrdering(int k,vector<vector<int>> &rowConditions,bool &cyclePresent,vector<int> &rowOrdering){
        // wrt row
        int i,u,v;
        
        // 1
        vector<vector<int>> adjList(k);
        for(i=0 ; i<rowConditions.size() ; i++){
            u = (rowConditions[i][0] - 1), v = (rowConditions[i][1] - 1);
            adjList[u].push_back(v);
        }
        
        // 2.1
        cyclePresent = isCyclic(k,adjList);
        if(cyclePresent){
            return;
        }
        

        // 2.2
        vector<bool> visited(k+1,false);
        deque<int> ordering;        
        for(i=0 ; i<k ; i++){
            if(!visited[i]){
                topoSort(i,visited,ordering,adjList);
            }   
        }                

        for(auto x : ordering){
            rowOrdering.push_back(x);
        }
        
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int i,u,v;
                
        // Row Ordering
        bool cyclePresent = false;
        vector<int> rowOrdering;
        findOrdering(k,rowConditions,cyclePresent,rowOrdering);
        
        if(cyclePresent){
            vector<vector<int>> empty;
            return empty;
        }
        
        // Column Ordering
        cyclePresent = false;
        vector<int> colOrdering;
        findOrdering(k,colConditions,cyclePresent,colOrdering);
        
        if(cyclePresent){
            vector<vector<int>> empty;
            return empty;
        }

        
        // Final Solution
        vector<int> rowIdx(k);
        for(i=0 ; i<rowOrdering.size() ; i++){
            rowIdx[rowOrdering[i]] = i;
        }
        
        vector<int> colIdx(k);
        for(i=0 ; i<colOrdering.size() ; i++){
            colIdx[colOrdering[i]] = i;
        }
                
        vector<vector<int>> solution(k,vector<int>(k,0));
        for(i=0 ; i<k ; i++){
            solution[rowIdx[i]][colIdx[i]] = (i+1);
        }
        
        return solution;                        
    }
};