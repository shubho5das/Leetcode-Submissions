class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i,n,mx;
        
        // 1 
        mx = 0;
        n = candies.size();
        for(i=0 ; i<n ; i++){
            mx = max(mx,candies[i]);
        }
        
        // 2 
        vector<bool> solution(n);
        for(i=0 ; i<n ; i++){
            if((candies[i] + extraCandies) >= mx){
                solution[i] = true;
            }
            else{
                solution[i] = false;
            }
        }
        
        return solution;
    }
};