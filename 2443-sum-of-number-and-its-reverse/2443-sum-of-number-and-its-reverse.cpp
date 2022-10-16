class Solution {
public:
    int findReverse(int num){
        // Reference: https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }    
    
    bool sumOfNumberAndReverse(int num) {
        int i,value,reversedValue,sum;
        
        for(i=0 ; i<=num ; i++){
            value = i;            
            reversedValue = findReverse(i);
            
            if((value + reversedValue) == num){
                return true;
            }
        }
        
        return false;
    }
};