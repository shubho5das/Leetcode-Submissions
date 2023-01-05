class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        if(a[1] == b[1]){
            return (a[0] < b[0]);
        }
        
        return(a[1] < b[1]);
    }
    
    int findMinArrowShots(vector<vector<int>>& segment) {
        long long n,i,cnt,current;
        n = segment.size();
        
        sort(segment.begin(),segment.end(),compare);
        
        cnt = 0, current = (-1e10);
        for(i=0 ; i<n ; i++){
            if(segment[i][0] > current ){
                cnt++;
                current = segment[i][1];
            }
        }
        return cnt;
    }
};