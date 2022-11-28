class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int i,n;
        n = matches.size();
        
        // 1
        map<int,int> M; // {player,#losses}
        
        for(i=0 ; i<n ; i++){
            // Winner
            if(M.find(matches[i][0]) == M.end()){
                M[matches[i][0]] = 0;
            }
            
            // Loser
            M[matches[i][1]]++;            
        }
        
        // 2
        vector<int> LosesZeroMatches;
        vector<int> LosesOneMatch;
        
        for(auto x : M){
            if(x.second == 0){
                LosesZeroMatches.push_back(x.first);
            }
            
            if(x.second == 1){
                LosesOneMatch.push_back(x.first);
            }            
        }
        
        return {LosesZeroMatches,LosesOneMatch};
    }
};