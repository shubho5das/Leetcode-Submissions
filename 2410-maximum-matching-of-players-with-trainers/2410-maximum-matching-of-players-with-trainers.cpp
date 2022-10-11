class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n,m,i,j,cnt;
        n = players.size(), m = trainers.size();
        
        // 1
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        
        // 2
        j = 0, cnt = 0;
        for(i=0 ; i<n ; i++){
            while(j<m && trainers[j] < players[i]){
                j++;
            }
            
            if(j<m && trainers[j] >= players[i]){
                cnt++;
            }
            
            j++;
        }
        
        return cnt;
    }
};