class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long i,j,n,currentValue,ans;
        n = nums.size();
            
        ans = 0;                
        i = 0, j = (n-1);
        while(i <= j){
            if(i == j){                
                currentValue = nums[i];
                ans += currentValue;                
                break;
            }
            else{
                string str;
                str += to_string(nums[i]);
                str += to_string(nums[j]);
                currentValue = stoi(str);
                ans += currentValue;
                i++, j--;
            }
        }

        return ans;
    }
};