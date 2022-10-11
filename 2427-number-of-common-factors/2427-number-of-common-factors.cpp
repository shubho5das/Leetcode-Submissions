class Solution {
public:
    int commonFactors(int a, int b) {
        int f,cnt;
        
        cnt = 0;
        for(f=1 ; f <= min(a,b) ; f++){
            if( (a%f == 0) && (b%f == 0)){
                cnt++;
            }
        }
        
        return cnt;        
    }
};