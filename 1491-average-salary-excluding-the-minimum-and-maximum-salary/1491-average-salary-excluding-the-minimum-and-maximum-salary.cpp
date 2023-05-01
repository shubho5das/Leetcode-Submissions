#define inf 1000000000

class Solution {
public:
    double average(vector<int>& salary) {
        int n,i,sum,mn,mx;
        n = salary.size();
        
        sum = 0, mn = inf, mx = -inf;
        for(i=0 ; i<n ; i++){
            sum += salary[i];
            mn = min(salary[i],mn);
            mx = max(salary[i],mx);                                
        }
        
        double ans = ((sum - mn - mx) * 1.0)/(n-2);
        return ans;
    }
};