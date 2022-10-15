class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long i,n,u,v,ans,maxScore;
        n = edges.size();
        
        vector<long long> edgeScore(n,0);
        for(i=0 ; i<n ; i++){
            u = i, v = edges[i];
            edgeScore[v] += u;
        }
        
        ans = -1, maxScore = -1;
        for(i=0 ; i<n ; i++){
            if(edgeScore[i] > maxScore){
                ans = i;
                maxScore = edgeScore[i];                
            }
        }
        
        return ans;
    }
};