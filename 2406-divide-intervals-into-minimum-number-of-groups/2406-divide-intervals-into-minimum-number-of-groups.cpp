class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n,l,r,i,currentCost,maxCost;
        n = intervals.size();
        
        // Line Sweep Algorithm
        map<int,int> M;
        for(i=0 ; i<n ; i++){
            l = intervals[i][0], r = intervals[i][1];
            M[l] += 1;
            M[r+1] -= 1;
        }
        
        currentCost = 0;
        maxCost = 0;
        for(auto x : M){
            maxCost = max(maxCost,currentCost);
            currentCost += x.second;            
        }
        
        return maxCost;                        
    }
};