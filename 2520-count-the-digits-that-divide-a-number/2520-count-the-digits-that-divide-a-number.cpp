class Solution {
public:
    int countDigits(int num) {
        int val,cnt,digit;        
        val = num;
        
        cnt = 0;
        while(num > 0){
            digit = num%10;
            if(val%digit == 0){
                cnt++;
            }
            num /= 10;
        }
        
        return cnt;
    }
};