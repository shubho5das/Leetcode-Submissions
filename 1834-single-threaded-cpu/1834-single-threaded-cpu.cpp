class Solution {
public:    
    vector<int> getOrder(vector<vector<int>>& V) {
        int n,i,currentTime,burstTime,id;
        n = V.size();
        
        vector<vector<int>> tasks(n);
        for(i=0 ; i<n ; i++){
            tasks[i] = {V[i][0],V[i][1],i};
        }
        
        sort(tasks.begin(),tasks.end());
        
        set<pair<int,int>> P; // {burstTime,id}     (available tasks)
        vector<int> solution;        
        currentTime = 0;
        for(i=0 ; i<n ; ){            
            if(P.size() == 0 && currentTime < tasks[i][0]){
                currentTime = tasks[i][0];                
            }
                                        
            while(i<n && tasks[i][0] <= currentTime){
                P.insert({tasks[i][1],tasks[i][2]});
                i++;
            }
            
            // Choosing the task for processing
            id = (*(P.begin())).second;
            burstTime = (*(P.begin())).first;
            P.erase(P.begin());
                        
            solution.push_back(id);
            currentTime = (currentTime + burstTime);
        }
                    
        while(P.size() >= 1){
            id = (*(P.begin())).second;
            burstTime = (*(P.begin())).first;
            P.erase(P.begin());            
            solution.push_back(id);            
        }
        
        return solution;        
    }
};