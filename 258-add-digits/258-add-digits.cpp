class Solution {
public:
    int findSumOfDigits(int num){
        int sum;
        
        sum = 0;
        while(num > 0){
            sum += (num%10);
            num /= 10;
        }
        
        return sum;
    }
    
    int addDigits(int num) {
        while(num >= 10){
            num = findSumOfDigits(num);
        }
        
        return num;
    }
};