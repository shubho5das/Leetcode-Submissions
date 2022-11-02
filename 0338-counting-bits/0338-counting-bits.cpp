class Solution {
public:
    vector<int> countBits(int n) {
        // Solve in O(n) time in the evening
        int i;
        
        vector<int> solution(n+1);
        for(i=0 ; i<=n ; i++){
            solution[i] = __builtin_popcount(i);
        }
        
        return solution;        
    }
};