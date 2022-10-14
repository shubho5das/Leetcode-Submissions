class Solution {
public:
    string shiftingLetters(string S, vector<vector<int>>& shifts) {
        int n,i,l,r,cost;
        n = S.length();
        
        vector<int> arr(n);
        for(i=0 ; i<n ; i++){
            arr[i] = (int)(S[i] - 'a');
        }
                
        // 1: Determing netShift[] using Line Sweep Algorithm                        
        vector<int> netShift(n+5,0);
        for(i=0 ; i<shifts.size() ; i++){
            l = shifts[i][0], r = shifts[i][1];
            cost = (shifts[i][2] == 1)? 1 : -1;
            
            netShift[l] = (netShift[l] + cost + 26)%26;
            netShift[r+1] = (netShift[r+1] - cost + 26)%26;
        }
        
        for(i=1 ; i<n ; i++){
            netShift[i] += netShift[i-1];
        }
                        
        // 2: Determining the final string                        
        string solution;
        for(i=0 ; i<n ; i++){
            arr[i] = (arr[i] + netShift[i] + 26)%26;
            char c = (char)((int)('a') + arr[i]);
            solution += c;
        }
        
        return solution;
    }
};