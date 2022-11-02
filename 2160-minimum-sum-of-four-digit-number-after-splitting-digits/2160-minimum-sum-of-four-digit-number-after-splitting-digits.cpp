// Small Constraints. Simple Brute Force!
#define inf 1000000000

class Solution {
public:
    int minimumSum(int num) {
        int num1,num2,cnt,digit,currentSum,minSum;
        
        
        // 1
        vector<int> V;
        cnt = 4;
        while(cnt--){
            digit = num%10;
            V.push_back(digit);
            num /= 10;
        }
        
        vector<int> index = {0,1,2,3};
        
        // 2
        minSum = inf;
        do{
            num1 = (10*V[index[0]] + V[index[1]]);
            num2 = (10*V[index[2]] + V[index[3]]);
            currentSum = (num1 + num2);

            minSum = min(currentSum,minSum);
            
        }
        while(next_permutation(index.begin(),index.end()));
        
        return minSum;
    }
};