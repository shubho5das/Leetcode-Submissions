class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n,i,cnt;
        n = costs.size();
        
        sort(costs.begin(),costs.end());
        
        cnt = 0;
        for(i=0 ; i<n ; i++){
            if(coins >= costs[i]){
                cnt++;
                coins -= costs[i];
            }
            else{
                break;
            }
        }
        
        return cnt;
    }
};