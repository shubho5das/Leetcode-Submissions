class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n,i,s,cnt,currentSum;
        n = gas.size();
        
        vector<int> diff(2*n);
        for(i=0 ; i<n ; i++){
            diff[i] = (gas[i] - cost[i]);
            diff[i+n] = (gas[i] - cost[i]);            
        }
        
        for(i=0 ; i<2*n ; ){
            if(diff[i] >= 0){
                currentSum = 0;                
                s = i, cnt = 0;
                while(i < 2*n && cnt < n && (currentSum + diff[i]) >= 0){
                    currentSum += diff[i];
                    cnt++, i++;
                }
                
                if(cnt == n){
                    return s;
                }                
            }
            else{
                i++;
            }
        }
        
        return -1;
    }
};