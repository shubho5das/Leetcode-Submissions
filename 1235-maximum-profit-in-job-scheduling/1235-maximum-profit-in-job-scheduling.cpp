class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profitArray) {
        int n,i,j,s,e,profit;
        
        // 1.1
        set<int> P;
        for(i=0 ; i<startTime.size() ; i++){
            P.insert(startTime[i]);
            P.insert(endTime[i]);
        }
        
        vector<int> points;
        unordered_map<int,int> pointIndex; // {point,idx}
        i = 0;
        for(auto x : P){
            points.push_back(x);    
            pointIndex[x] = i;
            i++;
        }
        
        n = points.size();
                        
        // 1.2
        map<int,vector<pair<int,int>>> M;  // {s,{e,profit}}
        for(i=0 ; i<startTime.size() ; i++){
            M[startTime[i]].push_back({endTime[i],profitArray[i]});
        }
                
        // 2
        vector<int> dp(n+5,0);
        // Base Case
        dp[n-1] = 0;
        // General Case
        for(i=(n-2) ; i>=0 ; i--){
            dp[i] = max(dp[i],dp[i+1]);
            
            s = points[i];
            if(M.find(s) != M.end()){
                vector<pair<int,int>> V = M[s];
                for(j=0 ; j<V.size() ; j++){
                    e = V[j].first, profit = V[j].second;                    
                    dp[i] = max(dp[i],(profit + dp[pointIndex[e]]));                      
                }                                    
            }                        
        }
        
        return dp[0];
    }
};