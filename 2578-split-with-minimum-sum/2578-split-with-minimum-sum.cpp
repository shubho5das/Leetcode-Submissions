class Solution {
public:
    static bool compare(int a, int b){
        return a > b;
    }
    
    int splitNum(int num) {
        int i,n,ans,x;
        
        // 1
        vector<int> digits;
        while(num > 0){
            digits.push_back(num%10);
            num /= 10;
        }
        
        n = digits.size();
        sort(digits.begin(),digits.end(),compare);
        
        // 2
        ans = 0, x = 1;
        for(i=0 ; i<n ; i++){
            ans += (digits[i] * x);
            
            if(i%2 != 0){
                x *= 10;   
            }            
        }
        
        return ans;      
    }
};