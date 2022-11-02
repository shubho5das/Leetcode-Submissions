#define inf 1000000000

class Solution {
public:
    bool isValidMutation(string &u,string &v){
        int i,cnt;
        
        cnt = 0;
        for(i=0 ; i<8 ; i++){
            if(u[i] != v[i]){
                cnt++;
            }
        }
        
        return (cnt == 1)? true : false;
    }
    
    int bfs_sssp(string &src,string &dest,vector<string> nodes, map<string,vector<string>> &adjList){
        int i;
        
        queue<string> Q;
        map<string,int> dist;
        for(i=0 ; i<nodes.size(); i++){
            dist[nodes[i]] = inf;
        }
        
        
        Q.push(src);
        dist[src] = 0;
        while(Q.size() >= 1){
            string currentNode = Q.front();
            Q.pop();
            
            // Pushing all the nbrs of currentNode
            for(auto nbr : adjList[currentNode]){
                if(dist[nbr] == inf){
                    Q.push(nbr);
                    dist[nbr] = (dist[currentNode] + 1);
                }
            }
        }
        
        return dist[dest];                
    }
    
    int minMutation(string start, string end, vector<string> &bank) {
        int n,i,j,ans;
        
        // 1: Constructing the Graph
        set<string> P; // To avoid duplicate nodeValues
        P.insert(start);
        P.insert(end);
        for(auto str : bank){  
            P.insert(str);
        }
                        
        vector<string> nodes;
        for(auto str : P){
            nodes.push_back(str);
        }
        n = nodes.size();
        
        bool isEndPresentInBank = false;
        for(i=0 ; i<bank.size() ; i++){
            if(bank[i] == end){
                isEndPresentInBank = true;
            }
        }
                        
        map<string,vector<string>> adjList;
        for(i=0 ; i<n ; i++){
            for(j=(i+1) ; j<n ; j++){
                string u = nodes[i];
                string v = nodes[j];
                
                if(isValidMutation(u,v)){                    
                    // The edges only exist between {start, banki values} 
                    if(u == end || v == end){
                        if(isEndPresentInBank){                            
                            adjList[u].push_back(v);
                            adjList[v].push_back(u);                                                   
                        }
                    }
                    else{
                        adjList[u].push_back(v);
                        adjList[v].push_back(u);                        
                    }                    
                }                
            }
        }
        
        // 2: bfs_sssp
        ans = bfs_sssp(start,end,nodes,adjList);
        if(ans == inf){
            ans = -1;
        }
        return ans;        
    }
};