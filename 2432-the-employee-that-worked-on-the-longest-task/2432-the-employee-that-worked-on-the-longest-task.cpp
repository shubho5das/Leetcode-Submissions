class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int i,t,ans,duration,maxDuration;
        
        t = 0;
        ans = -1, maxDuration = -1;
        for(i=0 ; i<logs.size() ; i++){
            duration = (logs[i][1] - t);
            if(duration > maxDuration){
                ans = logs[i][0];
                maxDuration = duration;
            }
            else if(duration == maxDuration){
                ans = min(ans,logs[i][0]);
            }
            
            t = logs[i][1];
        }
        
        return ans;
    }
};