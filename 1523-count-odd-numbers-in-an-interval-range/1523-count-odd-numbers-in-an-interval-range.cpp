class Solution {
public:
    int countOdds(int low, int high) {
        int gap,cnt;
        
        gap = (high - low + 1);
        if(gap%2 == 0){
            cnt = gap/2;
        }
        else{
            if(low%2 != 0){
                cnt = gap/2 + 1;
            }
            else{
                cnt = gap/2;
            }
        }
        
        return cnt;
    }
};