class Solution {
public:
    int bulbSwitch(int n) {
        int cnt,i;
        
        cnt = 0;
        i = 1;
        while((i*i) <= n){
            cnt++;
            i++;
        }
        
        return cnt;        
    }
};