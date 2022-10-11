class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n,i,k,cnt;
        n = grades.size();
                    
        cnt = 0;
        k = 1;
        while((n-k) >= 0){
            n -= k;
            k++;
            cnt++;
        }
        
        return cnt;
    }
};