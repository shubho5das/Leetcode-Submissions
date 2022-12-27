class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n,i,carry,value;
        n = digits.size();
        
        value = (digits[n-1] + 1);        
        digits[n-1] = value % 10;
        carry = value /10;
                
        for(i=(n-2) ; i>= 0 ; i--){
            value = (digits[i] + carry);
            digits[i] = value%10;
            carry = value/10;
        }
                        
        vector<int> solution;
        if(carry > 0){
            solution.push_back(carry);
        }
        for(i=0 ; i<n ; i++){
            solution.push_back(digits[i]);
        }
        
        return solution;
    }
};