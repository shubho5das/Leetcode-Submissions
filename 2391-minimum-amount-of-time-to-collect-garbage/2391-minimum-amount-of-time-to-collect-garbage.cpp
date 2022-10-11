class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n,i,j,idx,cnt,travelTime,ans;
        n = garbage.size();
        
        ans = 0;
        // G
        idx = -1;
        cnt = 0;
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<garbage[i].length() ; j++){
                if(garbage[i][j] == 'G'){
                    idx = i;
                    cnt++;
                }
            }
        }
        
        travelTime = 0;
        for(i=1 ; i<=idx ; i++){
            travelTime += travel[i-1];
        }
        
        ans += (travelTime + cnt);
        
        // P
        idx = -1;
        cnt = 0;
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<garbage[i].length() ; j++){
                if(garbage[i][j] == 'P'){
                    idx = i;
                    cnt++;
                }
            }
        }
        
        travelTime = 0;
        for(i=1 ; i<=idx ; i++){
            travelTime += travel[i-1];
        }
        
        ans += (travelTime + cnt);
        
        
        // M
        idx = -1;
        cnt = 0;
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<garbage[i].length() ; j++){
                if(garbage[i][j] == 'M'){
                    idx = i;
                    cnt++;
                }
            }
        }
        
        travelTime = 0;
        for(i=1 ; i<=idx ; i++){
            travelTime += travel[i-1];
        }
        
        ans += (travelTime + cnt);
        
        
        return ans;
    }
};